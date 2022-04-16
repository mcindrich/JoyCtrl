#include "joyctrl/configuration/button_combination.hpp"
#include "joyctrl/configuration/button_configuration.hpp"
#include <joyctrl/configuration/application_configuration.hpp>
#include <joyctrl/configuration/action_parser.hpp>
#include <joyctrl/log.hpp>

#include <iostream>
#include <regex>
#include <toml/value.hpp>

namespace joyctrl
{
namespace config
{
ApplicationConfiguration::ApplicationConfiguration(const toml::value &t)
{
    auto buttons = toml::find<toml::array>(t, "buttons");
    ActionParser action_parser;

    mComment = toml::find<std::string>(t, "comment");
    mRegexString = toml::find<std::string>(t, "regex");
    mRegex = std::regex(mRegexString);

    for (auto &button : buttons)
    {
        // for now only add first action
        mButtonConfigurations.push_back(ButtonConfiguration(
            ButtonCombination(toml::find<std::string>(button, "combination")),
            action_parser.parseActionString(toml::get<std::string>(toml::find<toml::array>(button, "actions").at(0)))));
    }
}
bool ApplicationConfiguration::searchRegex(const std::string &str)
{
    return std::regex_search(str, mRegex);
}
void ApplicationConfiguration::checkCurrentState(ujoy::Joystick &joystick, ForegroundWindow &fg_window)
{
    // button combinations
    for (auto &button_config : mButtonConfigurations)
    {
        if (button_config.Combination.matchesState(joystick))
        {
            log::debug("combination \'%s\' matched - executing action from the configuration file",
                       button_config.Combination.getCombinationString().c_str());
            if (button_config.ActionPtr)
            {
                button_config.ActionPtr->start(fg_window);
            }
        }
    }

    // analog trigger combinations

    // analog stick combinations
}
const std::string ApplicationConfiguration::getRegexString() const
{
    return mRegexString;
}
} // namespace config
} // namespace joyctrl
#include <joyctrl/configuration/button_combination.hpp>
#include <joyctrl/configuration/button_configuration.hpp>
#include <joyctrl/configuration/application_configuration.hpp>
#include <joyctrl/configuration/action/key_down.hpp>
#include <joyctrl/log.hpp>

#include <iostream>
#include <memory>
#include <regex>
#include <toml/value.hpp>

namespace joyctrl
{
namespace config
{
ApplicationConfiguration::ApplicationConfiguration(const toml::value &t)
{
    auto buttons = toml::find<toml::array>(t, "buttons");

    mComment = toml::find<std::string>(t, "comment");
    mRegexString = toml::find<std::string>(t, "regex");
    mRegex = std::regex(mRegexString);

    for (auto &button : buttons)
    {
        // for now only add first action
        const auto combination = ButtonCombination(toml::find<std::string>(button, "combination"));
        const auto toml_actions = toml::find<toml::array>(button, "actions");
        auto actions = mGetActions(toml_actions);

        mButtonConfigurations.push_back(ButtonConfiguration(combination, actions));
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
            for (auto &action : button_config.Actions)
            {
                action->start(fg_window);
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
std::list<std::unique_ptr<Action>> ApplicationConfiguration::mGetActions(const toml::array &t)
{
    std::list<std::unique_ptr<Action>> actions;

    for (auto &a : t)
    {
        const auto name = toml::find<std::string>(a, "name");
        const auto params = toml::find<std::vector<std::string>>(a, "params");

        if (name == "KeyDown")
        {
            actions.push_back(std::make_unique<action::KeyDown>(params));
        }
    }

    return actions;
}
} // namespace config
} // namespace joyctrl
#include <joyctrl/configuration/application_configuration.hpp>
#include <joyctrl/configuration/action_parser.hpp>
#include <joyctrl/log.hpp>

#include <iostream>

namespace joyctrl
{
namespace config
{
ApplicationConfiguration::ApplicationConfiguration(const nlohmann::json &j)
{
    const auto configuration_obj = j["configuration"];
    ActionParser action_parser;

    mComment = j["comment"];
    mRegexString = j["regex"].get<std::string>();
    mRegex = std::regex(mRegexString);

    for (auto &iter : configuration_obj["button_combinations"])
    {
        mButtonConfigurations.push_back(ButtonConfiguration(ButtonCombination(iter["combination"]), action_parser.parseActionString(iter["action"])));
    }
}
bool ApplicationConfiguration::searchRegex(const std::string &str)
{
    return std::regex_search(str, mRegex);
}
void ApplicationConfiguration::checkCurrentState(Joystick &joystick, ForegroundWindow &fg_window)
{
    // button combinations
    for (auto &button_config : mButtonConfigurations)
    {
        if (button_config.Combination.matchesState(joystick))
        {
            log::debug("combination \'%s\' matched - executing action from the configuration file", button_config.Combination.getCombinationString().c_str());
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
}
} // namespace joyctrl
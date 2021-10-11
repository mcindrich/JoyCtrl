#include <joyctrl/configuration/action_parser.hpp>
#include <joyctrl/configuration/action/key_down.hpp>
#include <joyctrl/utils.hpp>
#include <joyctrl/log.hpp>

namespace joyctrl
{
namespace config
{
ActionParser::ActionParser()
{
}

std::unique_ptr<Action> ActionParser::parseActionString(const std::string &action)
{
    std::unique_ptr<Action> action_ptr = nullptr;
    const std::array delims = {' '};
    
    auto args = utils::splitStringByDelimiters(action, delims);

    if (args.size())
    {
        const auto action_name = args[0];

        if (action_name == "KeyDown")
        {
            action_ptr = std::make_unique<action::KeyDown>(args);
        }
    }
    else
    {
        // invalid -> exception
    }

    return action_ptr;
}
}
}

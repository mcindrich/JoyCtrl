#include <joyctrl/configuration/action_parser.hpp>

namespace joyctrl
{
namespace cfg
{
ActionParser::ActionParser()
{
}

std::unique_ptr<Action> ActionParser::parseActionString(const std::string &action)
{
    std::unique_ptr<Action> action_ptr = nullptr;
    return action_ptr;
}
}
}

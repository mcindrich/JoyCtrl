#pragma once

#include <joyctrl/configuration/action.hpp>

#include <string>
#include <memory>

namespace joyctrl
{
namespace cfg
{
class ActionParser
{
  public:
    ActionParser();

    std::unique_ptr<Action> parseActionString(const std::string &action);

  private:

};
}
}
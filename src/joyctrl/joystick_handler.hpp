#pragma once

#include <joyctrl/configuration.hpp>

namespace joyctrl
{
class JoystickHandler
{
  public:
    JoystickHandler();

    void runOnIndex(int index, Configuration &config);
};
}
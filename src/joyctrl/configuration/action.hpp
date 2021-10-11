#pragma once

#include <joyctrl/foreground_window.hpp>

#include <string>
#include <vector>

namespace joyctrl
{
namespace config
{
class Action
{
  public:
    virtual void start(ForegroundWindow &fg_window) = 0;
};
}
}
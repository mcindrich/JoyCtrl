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
    Action(const std::vector<std::string> &params) : mParams(params)
    {
    }

    virtual void start(ForegroundWindow &fg_window) = 0;

    virtual ~Action() = default;

  protected:
    std::vector<std::string> mParams;
};
} // namespace config
} // namespace joyctrl
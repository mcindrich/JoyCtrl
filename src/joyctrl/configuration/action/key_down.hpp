#pragma once

#include <joyctrl/configuration/action.hpp>

namespace joyctrl
{
namespace config
{
namespace action
{
class KeyDown : public Action
{
  public:
    KeyDown(std::vector<std::string> &args);

    void start(ForegroundWindow &fg_window) override;

  private:
    VirtualKey mKey;
};
}
}
}
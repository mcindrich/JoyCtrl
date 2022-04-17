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
    KeyDown(const std::vector<std::string> &params);

    void start(ForegroundWindow &fg_window) override;

  private:
    VirtualKey mKey;
};
} // namespace action
} // namespace config
} // namespace joyctrl
#pragma once

#include <joyctrl/configuration/button_combination.hpp>
#include <joyctrl/configuration/action.hpp>

#include <memory>
#include <list>

namespace joyctrl
{
namespace config
{
struct ButtonConfiguration
{
    ButtonCombination Combination;
    std::list<std::unique_ptr<Action>> Actions;

    ButtonConfiguration(ButtonCombination combo, std::list<std::unique_ptr<Action>> &actions)
        : Combination(combo), Actions(std::move(actions))
    {
    }
};
} // namespace config
} // namespace joyctrl
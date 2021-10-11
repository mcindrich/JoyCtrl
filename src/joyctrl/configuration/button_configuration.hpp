#pragma once

#include <joyctrl/configuration/button_combination.hpp>
#include <joyctrl/configuration/action.hpp>

#include <memory>

namespace joyctrl
{
namespace cfg
{
struct ButtonConfiguration
{
    ButtonCombination Combination;
    std::unique_ptr<Action> ActionPtr;

    ButtonConfiguration(ButtonCombination combo, std::unique_ptr<Action> action): Combination(combo), ActionPtr(std::move(action))
    {
    }
};
}
}
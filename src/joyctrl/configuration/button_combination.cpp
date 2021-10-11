#include <joyctrl/configuration/button_combination.hpp>
#include <joyctrl/log.hpp>
#include <joyctrl/utils.hpp>

#include <list>
#include <array>
#include <map>
#include <stack>
#include <iostream>

namespace joyctrl
{
namespace config
{
ButtonCombination::ButtonCombination(const std::string &combo) : mCombinationString(combo)
{
    const std::array combo_symbols = {'+', '-'};
    auto is_combo_symbol = [&combo_symbols](std::string tok) {
        for (auto sym : combo_symbols)
        {
            if (std::string(1, sym) == tok)
            {
                return true;
            }
        }
        return false;
    };
    std::map<std::string, int> combo_sym_prior = {
        {"+", 1},
        {"-", 1},
    };

    std::stack<std::shared_ptr<AST::Node>> node_stack;
    std::stack<std::string> combo_stack;

    auto tokens = utils::splitStringByDelimiters(combo, combo_symbols);

    for (auto &tok : tokens)
    {
        if (is_combo_symbol(tok))
        {
            while (combo_stack.size() > 0 && combo_sym_prior[combo_stack.top()] >= combo_sym_prior[tok])
            {
                auto sym = combo_stack.top();
                combo_stack.pop();

                auto right = node_stack.top();
                node_stack.pop();
                auto left = node_stack.top();
                node_stack.pop();

                node_stack.push(std::make_shared<AST::ComboNode>(sym, left, right));
            }

            // push current token to stack
            combo_stack.push(tok);
        }
        else
        {
            // not a combination symbol -> value
            node_stack.push(std::make_shared<AST::ValueNode>(tok));
        }
    }

    while (combo_stack.size() > 0)
    {
        auto sym = combo_stack.top();
        combo_stack.pop();

        auto right = node_stack.top();
        node_stack.pop();
        auto left = node_stack.top();
        node_stack.pop();

        node_stack.push(std::make_shared<AST::ComboNode>(sym, left, right));
    }

    if (node_stack.size() == 1)
    {
        // valid
        mRootNode = node_stack.top();
        node_stack.pop();
    }
    else
    {
        // exception -> invalid
    }
}

void ButtonCombination::printAST() const
{
    log::debug("Combination AST: ");
    printNode(mRootNode);
    log::debug("");
}

bool ButtonCombination::matchesState(Joystick &joystick) const
{
    return checkNodeState(mRootNode, joystick);
}

const std::string ButtonCombination::getCombinationString() const
{
    return mCombinationString;
}

bool ButtonCombination::checkNodeState(const std::shared_ptr<AST::Node> &node, Joystick &joystick) const
{
    if (!node)
    {
        return false;
    }

    if (node->isComboNode())
    {
        if (node->Data == "+")
        {
            return checkNodeState(node->Left, joystick) && checkNodeState(node->Right, joystick);
        }
        else if (node->Data == "-")
        {
            return checkNodeState(node->Left, joystick) && !checkNodeState(node->Right, joystick);
        }
        else
        {
            return false;
        }
    }
    else
    {
        std::shared_ptr<AST::ValueNode> value = std::static_pointer_cast<AST::ValueNode>(node);
        if (joystick.isButtonPressed(value->Button))
        {
            log::debug("button \'%s\' pressed", value->Data.c_str());
            return true;
        }
        return false;
    }
}

void ButtonCombination::printNode(const std::shared_ptr<AST::Node> &node, int indent) const
{
    if (!node)
    {
        return;
    }

    for (auto i = 0; i < indent; i++)
    {
        printf("  ");
    }

    log::debug("\'%s\'", node->Data.c_str());

    if (node->isComboNode())
    {
        printNode(node->Left, indent + 1);
        printNode(node->Right, indent + 1);
    }
}
} // namespace config
}
#pragma once

#include <joyctrl/joystick.hpp>

#include <string>
#include <map>
#include <memory>

namespace joyctrl
{
namespace config
{
namespace AST
{
struct Node
{
    std::string Data;
    std::shared_ptr<Node> Left;
    std::shared_ptr<Node> Right;

    bool isComboNode() const
    {
        return Left != nullptr && Right != nullptr;
    }

    bool isValueNode() const
    {
        return !isComboNode();
    }
};
struct ComboNode : public Node
{
  public:
    ComboNode(std::string data, std::shared_ptr<Node> left, std::shared_ptr<Node> right)
    {
        Data = data;
        Left = left;
        Right = right;
    }
};
struct ValueNode : public Node
{
  public:
    JoystickButton Button;

    ValueNode(std::string data)
    {
        std::map<std::string, JoystickButton> buttons_map = {
            {"DPadUp", JoystickButton::DPadUp},
            {"DPadDown", JoystickButton::DPadDown},
            {"DPadLeft", JoystickButton::DPadLeft},
            {"DPadRight", JoystickButton::DPadRight},
            {"Start", JoystickButton::Start},
            {"Back", JoystickButton::Back},
            {"LS", JoystickButton::LS},
            {"RS", JoystickButton::RS},
            {"LB", JoystickButton::LB},
            {"RB", JoystickButton::RB},
            {"A", JoystickButton::A},
            {"B", JoystickButton::B},
            {"X", JoystickButton::X},
            {"Y", JoystickButton::Y},
        };

        Data = data;
        Button = buttons_map[Data];
    }
};
} // namespace AST
class ButtonCombination
{
  public:
    ButtonCombination(const std::string &combo);

    void printAST() const;

    bool matchesState(Joystick &joystick) const;

    const std::string getCombinationString() const;

  private:
    void printNode(const std::shared_ptr<AST::Node> &node, int indent = 0) const;
    bool checkNodeState(const std::shared_ptr<AST::Node> &node, Joystick &joystick) const;

    std::shared_ptr<AST::Node> mRootNode;
    std::string mCombinationString;
};
} // namespace config
} // namespace joyctrl

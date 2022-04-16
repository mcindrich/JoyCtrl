#pragma once

#include <UJoy++.hpp>

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
    ujoy::Button Button;

    ValueNode(std::string data)
    {
        std::map<std::string, ujoy::Button> buttons_map = {
            {"DPadUp", ujoy::Button::DPadUp},
            {"DPadDown", ujoy::Button::DPadDown},
            {"DPadLeft", ujoy::Button::DPadLeft},
            {"DPadRight", ujoy::Button::DPadRight},
            {"Start", ujoy::Button::Start},
            {"Back", ujoy::Button::Back},
            {"LS", ujoy::Button::LS},
            {"RS", ujoy::Button::RS},
            {"LB", ujoy::Button::LB},
            {"RB", ujoy::Button::RB},
            {"A", ujoy::Button::A},
            {"B", ujoy::Button::B},
            {"X", ujoy::Button::X},
            {"Y", ujoy::Button::Y},
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

    bool matchesState(ujoy::Joystick &joystick) const;

    const std::string getCombinationString() const;

  private:
    void printNode(const std::shared_ptr<AST::Node> &node, int indent = 0) const;
    bool checkNodeState(const std::shared_ptr<AST::Node> &node, ujoy::Joystick &joystick) const;

    std::shared_ptr<AST::Node> mRootNode;
    std::string mCombinationString;
};
} // namespace config
} // namespace joyctrl

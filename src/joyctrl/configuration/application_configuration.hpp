#pragma once

#include <joyctrl/configuration/button_configuration.hpp>

#include <regex>

#include <nlohmann/json.hpp>
#include <toml.hpp>

#include <list>

#include <UJoy++.hpp>
#include <toml/value.hpp>

namespace joyctrl
{
namespace config
{
class ApplicationConfiguration
{
  public:
    ApplicationConfiguration(const toml::value &t);

    bool searchRegex(const std::string &str);

    void checkCurrentState(ujoy::Joystick &joystick, ForegroundWindow &fg_window);

    const std::string getRegexString() const;

  private:
    std::list<std::unique_ptr<Action>> mGetActions(const toml::array &t);

    std::string mRegexString;
    std::regex mRegex;
    std::string mComment;

    std::list<ButtonConfiguration> mButtonConfigurations;
};
} // namespace config
} // namespace joyctrl
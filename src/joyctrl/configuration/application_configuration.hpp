#pragma once

#include <joyctrl/configuration/button_configuration.hpp>
#include <joyctrl/joystick.hpp>

#include <regex>

#include <nlohmann/json.hpp>
#include <toml.hpp>

#include <list>

namespace joyctrl
{
namespace config
{
class ApplicationConfiguration
{
  public:
    ApplicationConfiguration(const nlohmann::json &j);
    ApplicationConfiguration(const toml::value &t);

    bool searchRegex(const std::string &str);

    void checkCurrentState(Joystick &joystick, ForegroundWindow &fg_window);

    const std::string getRegexString() const;

  private:
    std::string mRegexString;
    std::regex mRegex;
    std::string mComment;

    std::list<ButtonConfiguration> mButtonConfigurations;
};
} // namespace config
} // namespace joyctrl
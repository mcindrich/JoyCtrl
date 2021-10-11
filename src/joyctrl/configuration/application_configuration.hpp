#pragma once

#include <joyctrl/configuration/button_configuration.hpp>
#include <joyctrl/joystick.hpp>

#include <regex>

#include <nlohmann/json.hpp>

namespace joyctrl
{
namespace cfg
{
class ApplicationConfiguration
{
  public:
    ApplicationConfiguration(const nlohmann::json &j);

    bool searchRegex(const std::string &str);

    void checkCurrentState(Joystick &joystick);

    const std::string getRegexString() const;

  private:
    std::string mRegexString;
    std::regex mRegex;
    std::string mComment;

    std::list<ButtonConfiguration> mButtonConfigurations;
};
}
} // namespace joyctrl
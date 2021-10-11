#pragma once

#include <joyctrl/configuration/application_configuration.hpp>

#include <map>
#include <string>

#include <nlohmann/json.hpp>

namespace joyctrl
{
struct Configuration
{
    std::map<std::string, std::list<cfg::ApplicationConfiguration>> Apps;

    Configuration();

    void createFromJSON(const nlohmann::json &j);
};
}
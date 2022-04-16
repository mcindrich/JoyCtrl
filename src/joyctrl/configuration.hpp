#pragma once

#include <joyctrl/configuration/application_configuration.hpp>

#include <map>
#include <string>

#include <nlohmann/json.hpp>
#include <toml.hpp>

namespace joyctrl
{
struct Configuration
{
    std::map<std::string, std::list<config::ApplicationConfiguration>> Apps;

    Configuration();

    void createFromJSON(const nlohmann::json &j);
    void createFromTOML(const toml::value &table);
};
} // namespace joyctrl
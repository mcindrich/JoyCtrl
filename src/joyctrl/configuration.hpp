#pragma once

#include <joyctrl/configuration/application_configuration.hpp>

#include <map>
#include <string>

#include <toml.hpp>

namespace joyctrl
{
struct Configuration
{
    std::map<std::string, std::list<config::ApplicationConfiguration>> Apps;

    Configuration();

    void createFromTOML(const toml::value &table);
};
} // namespace joyctrl
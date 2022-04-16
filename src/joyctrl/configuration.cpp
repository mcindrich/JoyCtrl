#include <joyctrl/configuration.hpp>
#include <joyctrl/log.hpp>

#include <iostream>

namespace joyctrl
{
Configuration::Configuration()
{
}
void Configuration::createFromTOML(const toml::value &table)
{
    auto apps = toml::find(table, "apps");
    for (auto &app : apps.as_array())
    {
        for (auto &reg : toml::find<toml::array>(app, "regex"))
        {
            const auto name = toml::find<std::string>(app, "name");
            this->Apps[name].push_back(config::ApplicationConfiguration(reg));
        }
    }
}
} // namespace joyctrl
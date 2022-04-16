#include <joyctrl/configuration.hpp>
#include <joyctrl/log.hpp>

#include <iostream>

namespace joyctrl
{
Configuration::Configuration()
{
}
void Configuration::createFromJSON(const nlohmann::json &j)
{
    const auto applications_obj = j["applications"].get<nlohmann::json::object_t>();
    for (auto &app : applications_obj)
    {
        for (auto &single_regex : app.second)
        {
            this->Apps[app.first].push_back(config::ApplicationConfiguration(single_regex));
        }
    }
}
void Configuration::createFromTOML(const toml::value &table)
{
    auto apps = toml::find(table, "apps");
    for (auto &app : apps.as_array())
    {
        for (auto &reg : toml::find<toml::array>(app, "regex"))
        {
            this->Apps[toml::find<std::string>(app, "name")].push_back(config::ApplicationConfiguration(reg));
        }
    }
}
} // namespace joyctrl
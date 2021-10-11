#include <joyctrl/configuration.hpp>
#include <joyctrl/log.hpp>

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
}
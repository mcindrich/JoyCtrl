// lib
#include <joyctrl.hpp>

// stdlib
#include <iostream>
#include <fstream>
#include <optional>

// libs
#include <nlohmann/json.hpp>
#include <argparse/argparse.hpp>
#include <stdexcept>

static std::optional<std::string> readFile(const std::string &path);

int main(int arg_n, char *args[])
{
    // 1: parse arguments
    argparse::ArgumentParser arg_parser(args[0], "1.0");
    joyctrl::Configuration configuration;
    joyctrl::JoystickHandler joystick_handler;

    arg_parser.add_argument("-c", "--config").required().help("path to the application configuration file");
    arg_parser.add_argument("-i", "--index").required().scan <'i', int>().help("joystick index to use - see XInput for more info");

    try
    {
        arg_parser.parse_args(arg_n, args);
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << "Error parsing given arguments: " << e.what() << std::endl;
        std::cerr << arg_parser << std::endl;
        return -1;
    }

    // 2: retrieve needed arguments
    const auto config_path = arg_parser.get<std::string>("-c");
    const auto joystick_index = arg_parser.get<int>("-i");

    joyctrl::log::info("using configuration file \'%s\'", config_path.c_str());
    joyctrl::log::info("using joystick index (%d)", joystick_index);

    // 3: load and parse config
    auto config_data = readFile(config_path);
    if (config_data.has_value())
    {
        try
        {
            const auto j = nlohmann::json::parse(config_data.value());
            configuration.createFromJSON(j);
        }
        catch (const nlohmann::json::parse_error e)
        {
            std::cerr << "Unable to parse configuration file \'" << config_path << "\': " << e.what() << std::endl;
            return -1;
        }
    }
    else
    {
        joyctrl::log::error("unable to read file \'%s\'", config_path.c_str());
        return -1;
    }

    // after creating the configuration -> init the joystick handler and run it on the provided index
    joystick_handler.runOnIndex(joystick_index, configuration);

    return 0;
}

static std::optional<std::string> readFile(const std::string &path)
{
    std::ifstream file(path);
    std::optional<std::string> content;

    if (file.is_open())
    {
        content = std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    }

    return content;
}
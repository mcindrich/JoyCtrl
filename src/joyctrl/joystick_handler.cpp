#include <joyctrl/joystick_handler.hpp>
#include <joyctrl/joystick.hpp>
#include <joyctrl/foreground_window.hpp>
#include <joyctrl/log.hpp>

namespace joyctrl
{
JoystickHandler::JoystickHandler()
{
}
void JoystickHandler::runOnIndex(int index, Configuration &config)
{
    Joystick joystick(index);
    ForegroundWindow fg_window;

    while (joystick.isConnected())
    {
        // process current configuration
        const auto exe_full = fg_window.getWindowExe();
        const auto title = fg_window.getWindowTitle();
        
        if (exe_full.size())
        {
            std::string exe;
#ifdef _WIN32
            exe = exe_full.substr(exe_full.find_last_of('\\') + 1);
#else
#endif
            // match app name and give joystick to the app config to poll for changes
            auto app = config.Apps.find(exe);
            if (app != config.Apps.end())
            {
                for (auto &app_config : app->second)
                {
                    if (app_config.searchRegex(title))
                    {
                        log::debug("matched regex \'%s\' for app %s (window title: %s)", app_config.getRegexString().c_str(), exe.c_str(), title.c_str());
                        app_config.checkCurrentState(joystick);
                    }
                }
            }
        }

#ifdef _WIN32
        Sleep(1000);
#else
#endif

        // refresh joystick configuration
        joystick.refresh();

        // refresh foreground window info
        fg_window.refresh();
    }
}
}
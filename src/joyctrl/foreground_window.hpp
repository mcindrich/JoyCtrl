#pragma once

#ifdef _WIN32
#include <windows.h>
#else
#endif

#include <string>

namespace joyctrl
{
// abstract representation of a foreground (main) window - both on windows and unix machines
class ForegroundWindow
{
  public:
    ForegroundWindow();

    void refresh();

    std::string getWindowTitle() const;
    std::string getWindowExe() const;

  private:
#ifdef _WIN32
    HWND mForegroundWindowHandle;
#else
#endif

};
} // namespace joyctrl

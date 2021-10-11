#include <joyctrl/foreground_window.hpp>
#include <joyctrl/log.hpp>

namespace joyctrl
{
ForegroundWindow::ForegroundWindow()
{
#ifdef _WIN32
    mForegroundWindowHandle = GetForegroundWindow();
#else
#endif
}

std::string ForegroundWindow::getWindowTitle() const
{
    std::string title;
    char title_buffer[2048] = {0};

    if (GetWindowText(mForegroundWindowHandle, title_buffer, sizeof(title_buffer)) > 0)
    {
        title = title_buffer;
    }

    return title;
}

std::string ForegroundWindow::getWindowExe() const
{
    std::string exe;
    char exe_buffer[2048] = {0};
    DWORD process_id = 0;
    DWORD chars_written = sizeof(exe_buffer);
    HANDLE process_handle = nullptr;

    GetWindowThreadProcessId(mForegroundWindowHandle, &process_id);
    process_handle = OpenProcess(0x0400 | 0x0010, false, process_id);

    bool success = QueryFullProcessImageName(process_handle, 0, exe_buffer, &chars_written);

    if (success && chars_written > 0)
    {
        exe = exe_buffer;
    }

    return exe;
}

void ForegroundWindow::refresh()
{
#ifdef _WIN32
    mForegroundWindowHandle = GetForegroundWindow();
#else
#endif
}
} // namespace joyctrl
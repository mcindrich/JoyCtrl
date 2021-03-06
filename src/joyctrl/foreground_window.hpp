#pragma once

#ifdef _WIN32
#include <windows.h>
#else
#endif

#include <string>

namespace joyctrl
{
enum class KeyboardInputNotification
{
    Activate = WM_ACTIVATE,
    AppCommand = WM_APPCOMMAND,
    Char = WM_CHAR,
    DeadChar = WM_DEADCHAR,
    HotKey = WM_HOTKEY,
    KeyDown = WM_KEYDOWN,
    KeyUp = WM_KEYUP,
    KillFocus = WM_KILLFOCUS,
    SetFocus = WM_SETFOCUS,
    SysDeadChar = WM_SYSDEADCHAR,
    SysKeyDown = WM_SYSKEYDOWN,
    SysKeyUp = WM_SYSKEYUP,
    UniChar = WM_UNICHAR,
};
enum class VirtualKey
{
    LButton = VK_LBUTTON,
    RButton = VK_RBUTTON,
    Cancel = VK_CANCEL,
    Mbutton = VK_MBUTTON,
    XButton1 = VK_XBUTTON1,
    XButton2 = VK_XBUTTON2,
    Back = VK_BACK,
    Tab = VK_TAB,
    Clear = VK_CLEAR,
    Return = VK_RETURN,
    Shift = VK_SHIFT,
    Control = VK_CONTROL,
    Menu = VK_MENU,
    Pause = VK_PAUSE,
    Capital = VK_CAPITAL,
    Kana = VK_KANA,
    Hangeul = VK_HANGEUL,
    Hangul = VK_HANGUL,
    Ime_On = VK_IME_ON,
    Junja = VK_JUNJA,
    Final = VK_FINAL,
    Hanja = VK_HANJA,
    Kanji = VK_KANJI,
    Ime_Off = VK_IME_OFF,
    Escape = VK_ESCAPE,
    Convert = VK_CONVERT,
    Nonconvert = VK_NONCONVERT,
    Accept = VK_ACCEPT,
    Modechange = VK_MODECHANGE,
    Space = VK_SPACE,
    Prior = VK_PRIOR,
    Next = VK_NEXT,
    End = VK_END,
    Home = VK_HOME,
    Left = VK_LEFT,
    Up = VK_UP,
    Right = VK_RIGHT,
    Down = VK_DOWN,
    Select = VK_SELECT,
    Print = VK_PRINT,
    Execute = VK_EXECUTE,
    Snapshot = VK_SNAPSHOT,
    Insert = VK_INSERT,
    Delete = VK_DELETE,
    Help = VK_HELP,
    Lwin = VK_LWIN,
    Rwin = VK_RWIN,
    Apps = VK_APPS,
    Sleep = VK_SLEEP,
    Numpad0 = VK_NUMPAD0,
    Numpad1 = VK_NUMPAD1,
    Numpad2 = VK_NUMPAD2,
    Numpad3 = VK_NUMPAD3,
    Numpad4 = VK_NUMPAD4,
    Numpad5 = VK_NUMPAD5,
    Numpad6 = VK_NUMPAD6,
    Numpad7 = VK_NUMPAD7,
    Numpad8 = VK_NUMPAD8,
    Numpad9 = VK_NUMPAD9,
    Multiply = VK_MULTIPLY,
    Add = VK_ADD,
    Separator = VK_SEPARATOR,
    Subtract = VK_SUBTRACT,
    Decimal = VK_DECIMAL,
    Divide = VK_DIVIDE,
    F1 = VK_F1,
    F2 = VK_F2,
    F3 = VK_F3,
    F4 = VK_F4,
    F5 = VK_F5,
    F6 = VK_F6,
    F7 = VK_F7,
    F8 = VK_F8,
    F9 = VK_F9,
    F10 = VK_F10,
    F11 = VK_F11,
    F12 = VK_F12,
    F13 = VK_F13,
    F14 = VK_F14,
    F15 = VK_F15,
    F16 = VK_F16,
    F17 = VK_F17,
    F18 = VK_F18,
    F19 = VK_F19,
    F20 = VK_F20,
    F21 = VK_F21,
    F22 = VK_F22,
    F23 = VK_F23,
    F24 = VK_F24,
    NavigationView = VK_NAVIGATION_VIEW,
    NavigationMenu = VK_NAVIGATION_MENU,
    NavigationUp = VK_NAVIGATION_UP,
    NavigationDown = VK_NAVIGATION_DOWN,
    NavigationLeft = VK_NAVIGATION_LEFT,
    NavigationRight = VK_NAVIGATION_RIGHT,
    NavigationAccept = VK_NAVIGATION_ACCEPT,
    NavigationCancel = VK_NAVIGATION_CANCEL,
    Numlock = VK_NUMLOCK,
    Scroll = VK_SCROLL,
    OemNecEqual = VK_OEM_NEC_EQUAL,
    OemFjJisho = VK_OEM_FJ_JISHO,
    OemFjMasshou = VK_OEM_FJ_MASSHOU,
    OemFjTouroku = VK_OEM_FJ_TOUROKU,
    OemFjLoya = VK_OEM_FJ_LOYA,
    OemFjRoya = VK_OEM_FJ_ROYA,
    LShift = VK_LSHIFT,
    RShift = VK_RSHIFT,
    LControl = VK_LCONTROL,
    RControl = VK_RCONTROL,
    LMenu = VK_LMENU,
    RMenu = VK_RMENU,
    BrowserBack = VK_BROWSER_BACK,
    BrowserForward = VK_BROWSER_FORWARD,
    BrowserRefresh = VK_BROWSER_REFRESH,
    BrowserStop = VK_BROWSER_STOP,
    BrowserSearch = VK_BROWSER_SEARCH,
    BrowserFavorites = VK_BROWSER_FAVORITES,
    BrowserHome = VK_BROWSER_HOME,
    VolumeMute = VK_VOLUME_MUTE,
    VolumeDown = VK_VOLUME_DOWN,
    VolumeUp = VK_VOLUME_UP,
    MediaNextTrack = VK_MEDIA_NEXT_TRACK,
    MediaPrevTrack = VK_MEDIA_PREV_TRACK,
    MediaStop = VK_MEDIA_STOP,
    MediaPlayPause = VK_MEDIA_PLAY_PAUSE,
    LaunchMail = VK_LAUNCH_MAIL,
    LaunchApp2 = VK_LAUNCH_APP2,
    Oem1 = VK_OEM_1,
    OemPlus = VK_OEM_PLUS,
    OemComma = VK_OEM_COMMA,
    OemMinus = VK_OEM_MINUS,
    OemPeriod = VK_OEM_PERIOD,
    Oem2 = VK_OEM_2,
    Oem3 = VK_OEM_3,
    GamepadA = VK_GAMEPAD_A,
    GamepadB = VK_GAMEPAD_B,
    GamepadX = VK_GAMEPAD_X,
    GamepadY = VK_GAMEPAD_Y,
    GamepadRightShoulder = VK_GAMEPAD_RIGHT_SHOULDER,
    GamepadLeftShoulder = VK_GAMEPAD_LEFT_SHOULDER,
    GamepadLeftTrigger = VK_GAMEPAD_LEFT_TRIGGER,
    GamepadRightTrigger = VK_GAMEPAD_RIGHT_TRIGGER,
    GamepadDpadUp = VK_GAMEPAD_DPAD_UP,
    GamepadDpadDown = VK_GAMEPAD_DPAD_DOWN,
    GamepadDpadLeft = VK_GAMEPAD_DPAD_LEFT,
    GamepadDpadRight = VK_GAMEPAD_DPAD_RIGHT,
    GamepadMenu = VK_GAMEPAD_MENU,
    GamepadView = VK_GAMEPAD_VIEW,
    GamepadLeftThumbstickButton = VK_GAMEPAD_LEFT_THUMBSTICK_BUTTON,
    GamepadRightThumbstickButton = VK_GAMEPAD_RIGHT_THUMBSTICK_BUTTON,
    GamepadLeftThumbstickUp = VK_GAMEPAD_LEFT_THUMBSTICK_UP,
    GamepadLeftThumbstickDown = VK_GAMEPAD_LEFT_THUMBSTICK_DOWN,
    GamepadLeftThumbstickRight = VK_GAMEPAD_LEFT_THUMBSTICK_RIGHT,
    GamepadLeftThumbstickLeft = VK_GAMEPAD_LEFT_THUMBSTICK_LEFT,
    GamepadRightThumbstickUp = VK_GAMEPAD_RIGHT_THUMBSTICK_UP,
    GamepadRightThumbstickDown = VK_GAMEPAD_RIGHT_THUMBSTICK_DOWN,
    GamepadRightThumbstickRight = VK_GAMEPAD_RIGHT_THUMBSTICK_RIGHT,
    GamepadRightThumbstickLeft = VK_GAMEPAD_RIGHT_THUMBSTICK_LEFT,
    Oem4 = VK_OEM_4,
    Oem5 = VK_OEM_5,
    Oem6 = VK_OEM_6,
    Oem7 = VK_OEM_7,
    Oem8 = VK_OEM_8,
    OemAx = VK_OEM_AX,
    Oem102 = VK_OEM_102,
    IcoHelp = VK_ICO_HELP,
    Ico00 = VK_ICO_00,
    ProcessKey = VK_PROCESSKEY,
    IcoClear = VK_ICO_CLEAR,
    Packet = VK_PACKET,
    OemReset = VK_OEM_RESET,
    OemJump = VK_OEM_JUMP,
    OemPa1 = VK_OEM_PA1,
    OemPa2 = VK_OEM_PA2,
    OemPa3 = VK_OEM_PA3,
    OemWsctrl = VK_OEM_WSCTRL,
    OemCusel = VK_OEM_CUSEL,
    OemAttn = VK_OEM_ATTN,
    OemFinish = VK_OEM_FINISH,
    OemCopy = VK_OEM_COPY,
    OemAuto = VK_OEM_AUTO,
    OemEnlw = VK_OEM_ENLW,
    OemBacktab = VK_OEM_BACKTAB,
    Attn = VK_ATTN,
    Crsel = VK_CRSEL,
    Exsel = VK_EXSEL,
    Ereof = VK_EREOF,
    Play = VK_PLAY,
    Zoom = VK_ZOOM,
    Noname = VK_NONAME,
    Pa1 = VK_PA1,
    OemClear = VK_OEM_CLEAR,
};
// abstract representation of a foreground (main) window - both on windows and unix machines
class ForegroundWindow
{
  public:
    ForegroundWindow();

    void refresh();

    std::string getWindowTitle() const;
    std::string getWindowExe() const;
    void simulateKeyDown(VirtualKey vk);

  private:
#ifdef _WIN32
    HWND mForegroundWindowHandle;
#else
#endif
};
} // namespace joyctrl

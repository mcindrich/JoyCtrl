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
#ifdef WIN32
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
#else
#endif
};
enum class VirtualKey
{
    LButton =

#ifdef WIN32
        VK_LBUTTON
#else
        0
#endif
    ,

    RButton =

#ifdef WIN32
        VK_RBUTTON
#else
        0
#endif
    ,

    Cancel =

#ifdef WIN32
        VK_CANCEL
#else
        0
#endif
    ,

    Mbutton =

#ifdef WIN32
        VK_MBUTTON
#else
        0
#endif
    ,

    XButton1 =

#ifdef WIN32
        VK_XBUTTON1
#else
        0
#endif
    ,

    XButton2 =

#ifdef WIN32
        VK_XBUTTON2
#else
        0
#endif
    ,

    Back =

#ifdef WIN32
        VK_BACK
#else
        0
#endif
    ,

    Tab =

#ifdef WIN32
        VK_TAB
#else
        0
#endif
    ,

    Clear =

#ifdef WIN32
        VK_CLEAR
#else
        0
#endif
    ,

    Return =

#ifdef WIN32
        VK_RETURN
#else
        0
#endif
    ,

    Shift =

#ifdef WIN32
        VK_SHIFT
#else
        0
#endif
    ,

    Control =

#ifdef WIN32
        VK_CONTROL
#else
        0
#endif
    ,

    Menu =

#ifdef WIN32
        VK_MENU
#else
        0
#endif
    ,

    Pause =

#ifdef WIN32
        VK_PAUSE
#else
        0
#endif
    ,

    Capital =

#ifdef WIN32
        VK_CAPITAL
#else
        0
#endif
    ,

    Kana =

#ifdef WIN32
        VK_KANA
#else
        0
#endif
    ,

    Hangeul =

#ifdef WIN32
        VK_HANGEUL
#else
        0
#endif
    ,

    Hangul =

#ifdef WIN32
        VK_HANGUL
#else
        0
#endif
    ,

    Ime_On =

#ifdef WIN32
        VK_IME_ON
#else
        0
#endif
    ,

    Junja =

#ifdef WIN32
        VK_JUNJA
#else
        0
#endif
    ,

    Final =

#ifdef WIN32
        VK_FINAL
#else
        0
#endif
    ,

    Hanja =

#ifdef WIN32
        VK_HANJA
#else
        0
#endif
    ,

    Kanji =

#ifdef WIN32
        VK_KANJI
#else
        0
#endif
    ,

    Ime_Off =

#ifdef WIN32
        VK_IME_OFF
#else
        0
#endif
    ,

    Escape =

#ifdef WIN32
        VK_ESCAPE
#else
        0
#endif
    ,

    Convert =

#ifdef WIN32
        VK_CONVERT
#else
        0
#endif
    ,

    Nonconvert =

#ifdef WIN32
        VK_NONCONVERT
#else
        0
#endif
    ,

    Accept =

#ifdef WIN32
        VK_ACCEPT
#else
        0
#endif
    ,

    Modechange =

#ifdef WIN32
        VK_MODECHANGE
#else
        0
#endif
    ,

    Space =

#ifdef WIN32
        VK_SPACE
#else
        0
#endif
    ,

    Prior =

#ifdef WIN32
        VK_PRIOR
#else
        0
#endif
    ,

    Next =

#ifdef WIN32
        VK_NEXT
#else
        0
#endif
    ,

    End =

#ifdef WIN32
        VK_END
#else
        0
#endif
    ,

    Home =

#ifdef WIN32
        VK_HOME
#else
        0
#endif
    ,

    Left =

#ifdef WIN32
        VK_LEFT
#else
        0
#endif
    ,

    Up =

#ifdef WIN32
        VK_UP
#else
        0
#endif
    ,

    Right =

#ifdef WIN32
        VK_RIGHT
#else
        0
#endif
    ,

    Down =

#ifdef WIN32
        VK_DOWN
#else
        0
#endif
    ,

    Select =

#ifdef WIN32
        VK_SELECT
#else
        0
#endif
    ,

    Print =

#ifdef WIN32
        VK_PRINT
#else
        0
#endif
    ,

    Execute =

#ifdef WIN32
        VK_EXECUTE
#else
        0
#endif
    ,

    Snapshot =

#ifdef WIN32
        VK_SNAPSHOT
#else
        0
#endif
    ,

    Insert =

#ifdef WIN32
        VK_INSERT
#else
        0
#endif
    ,

    Delete =

#ifdef WIN32
        VK_DELETE
#else
        0
#endif
    ,

    Help =

#ifdef WIN32
        VK_HELP
#else
        0
#endif
    ,

    Lwin =

#ifdef WIN32
        VK_LWIN
#else
        0
#endif
    ,

    Rwin =

#ifdef WIN32
        VK_RWIN
#else
        0
#endif
    ,

    Apps =

#ifdef WIN32
        VK_APPS
#else
        0
#endif
    ,

    Sleep =

#ifdef WIN32
        VK_SLEEP
#else
        0
#endif
    ,

    Numpad0 =

#ifdef WIN32
        VK_NUMPAD0
#else
        0
#endif
    ,

    Numpad1 =

#ifdef WIN32
        VK_NUMPAD1
#else
        0
#endif
    ,

    Numpad2 =

#ifdef WIN32
        VK_NUMPAD2
#else
        0
#endif
    ,

    Numpad3 =

#ifdef WIN32
        VK_NUMPAD3
#else
        0
#endif
    ,

    Numpad4 =

#ifdef WIN32
        VK_NUMPAD4
#else
        0
#endif
    ,

    Numpad5 =

#ifdef WIN32
        VK_NUMPAD5
#else
        0
#endif
    ,

    Numpad6 =

#ifdef WIN32
        VK_NUMPAD6
#else
        0
#endif
    ,

    Numpad7 =

#ifdef WIN32
        VK_NUMPAD7
#else
        0
#endif
    ,

    Numpad8 =

#ifdef WIN32
        VK_NUMPAD8
#else
        0
#endif
    ,

    Numpad9 =

#ifdef WIN32
        VK_NUMPAD9
#else
        0
#endif
    ,

    Multiply =

#ifdef WIN32
        VK_MULTIPLY
#else
        0
#endif
    ,

    Add =

#ifdef WIN32
        VK_ADD
#else
        0
#endif
    ,

    Separator =

#ifdef WIN32
        VK_SEPARATOR
#else
        0
#endif
    ,

    Subtract =

#ifdef WIN32
        VK_SUBTRACT
#else
        0
#endif
    ,

    Decimal =

#ifdef WIN32
        VK_DECIMAL
#else
        0
#endif
    ,

    Divide =

#ifdef WIN32
        VK_DIVIDE
#else
        0
#endif
    ,

    F1 =

#ifdef WIN32
        VK_F1
#else
        0
#endif
    ,

    F2 =

#ifdef WIN32
        VK_F2
#else
        0
#endif
    ,

    F3 =

#ifdef WIN32
        VK_F3
#else
        0
#endif
    ,

    F4 =

#ifdef WIN32
        VK_F4
#else
        0
#endif
    ,

    F5 =

#ifdef WIN32
        VK_F5
#else
        0
#endif
    ,

    F6 =

#ifdef WIN32
        VK_F6
#else
        0
#endif
    ,

    F7 =

#ifdef WIN32
        VK_F7
#else
        0
#endif
    ,

    F8 =

#ifdef WIN32
        VK_F8
#else
        0
#endif
    ,

    F9 =

#ifdef WIN32
        VK_F9
#else
        0
#endif
    ,

    F10 =

#ifdef WIN32
        VK_F10
#else
        0
#endif
    ,

    F11 =

#ifdef WIN32
        VK_F11
#else
        0
#endif
    ,

    F12 =

#ifdef WIN32
        VK_F12
#else
        0
#endif
    ,

    F13 =

#ifdef WIN32
        VK_F13
#else
        0
#endif
    ,

    F14 =

#ifdef WIN32
        VK_F14
#else
        0
#endif
    ,

    F15 =

#ifdef WIN32
        VK_F15
#else
        0
#endif
    ,

    F16 =

#ifdef WIN32
        VK_F16
#else
        0
#endif
    ,

    F17 =

#ifdef WIN32
        VK_F17
#else
        0
#endif
    ,

    F18 =

#ifdef WIN32
        VK_F18
#else
        0
#endif
    ,

    F19 =

#ifdef WIN32
        VK_F19
#else
        0
#endif
    ,

    F20 =

#ifdef WIN32
        VK_F20
#else
        0
#endif
    ,

    F21 =

#ifdef WIN32
        VK_F21
#else
        0
#endif
    ,

    F22 =

#ifdef WIN32
        VK_F22
#else
        0
#endif
    ,

    F23 =

#ifdef WIN32
        VK_F23
#else
        0
#endif
    ,

    F24 =

#ifdef WIN32
        VK_F24
#else
        0
#endif
    ,

    NavigationView =

#ifdef WIN32
        VK_NAVIGATION_VIEW
#else
        0
#endif
    ,

    NavigationMenu =

#ifdef WIN32
        VK_NAVIGATION_MENU
#else
        0
#endif
    ,

    NavigationUp =

#ifdef WIN32
        VK_NAVIGATION_UP
#else
        0
#endif
    ,

    NavigationDown =

#ifdef WIN32
        VK_NAVIGATION_DOWN
#else
        0
#endif
    ,

    NavigationLeft =

#ifdef WIN32
        VK_NAVIGATION_LEFT
#else
        0
#endif
    ,

    NavigationRight =

#ifdef WIN32
        VK_NAVIGATION_RIGHT
#else
        0
#endif
    ,

    NavigationAccept =

#ifdef WIN32
        VK_NAVIGATION_ACCEPT
#else
        0
#endif
    ,

    NavigationCancel =

#ifdef WIN32
        VK_NAVIGATION_CANCEL
#else
        0
#endif
    ,

    Numlock =

#ifdef WIN32
        VK_NUMLOCK
#else
        0
#endif
    ,

    Scroll =

#ifdef WIN32
        VK_SCROLL
#else
        0
#endif
    ,

    OemNecEqual =

#ifdef WIN32
        VK_OEM_NEC_EQUAL
#else
        0
#endif
    ,

    OemFjJisho =

#ifdef WIN32
        VK_OEM_FJ_JISHO
#else
        0
#endif
    ,

    OemFjMasshou =

#ifdef WIN32
        VK_OEM_FJ_MASSHOU
#else
        0
#endif
    ,

    OemFjTouroku =

#ifdef WIN32
        VK_OEM_FJ_TOUROKU
#else
        0
#endif
    ,

    OemFjLoya =

#ifdef WIN32
        VK_OEM_FJ_LOYA
#else
        0
#endif
    ,

    OemFjRoya =

#ifdef WIN32
        VK_OEM_FJ_ROYA
#else
        0
#endif
    ,

    LShift =

#ifdef WIN32
        VK_LSHIFT
#else
        0
#endif
    ,

    RShift =

#ifdef WIN32
        VK_RSHIFT
#else
        0
#endif
    ,

    LControl =

#ifdef WIN32
        VK_LCONTROL
#else
        0
#endif
    ,

    RControl =

#ifdef WIN32
        VK_RCONTROL
#else
        0
#endif
    ,

    LMenu =

#ifdef WIN32
        VK_LMENU
#else
        0
#endif
    ,

    RMenu =

#ifdef WIN32
        VK_RMENU
#else
        0
#endif
    ,

    BrowserBack =

#ifdef WIN32
        VK_BROWSER_BACK
#else
        0
#endif
    ,

    BrowserForward =

#ifdef WIN32
        VK_BROWSER_FORWARD
#else
        0
#endif
    ,

    BrowserRefresh =

#ifdef WIN32
        VK_BROWSER_REFRESH
#else
        0
#endif
    ,

    BrowserStop =

#ifdef WIN32
        VK_BROWSER_STOP
#else
        0
#endif
    ,

    BrowserSearch =

#ifdef WIN32
        VK_BROWSER_SEARCH
#else
        0
#endif
    ,

    BrowserFavorites =

#ifdef WIN32
        VK_BROWSER_FAVORITES
#else
        0
#endif
    ,

    BrowserHome =

#ifdef WIN32
        VK_BROWSER_HOME
#else
        0
#endif
    ,

    VolumeMute =

#ifdef WIN32
        VK_VOLUME_MUTE
#else
        0
#endif
    ,

    VolumeDown =

#ifdef WIN32
        VK_VOLUME_DOWN
#else
        0
#endif
    ,

    VolumeUp =

#ifdef WIN32
        VK_VOLUME_UP
#else
        0
#endif
    ,

    MediaNextTrack =

#ifdef WIN32
        VK_MEDIA_NEXT_TRACK
#else
        0
#endif
    ,

    MediaPrevTrack =

#ifdef WIN32
        VK_MEDIA_PREV_TRACK
#else
        0
#endif
    ,

    MediaStop =

#ifdef WIN32
        VK_MEDIA_STOP
#else
        0
#endif
    ,

    MediaPlayPause =

#ifdef WIN32
        VK_MEDIA_PLAY_PAUSE
#else
        0
#endif
    ,

    LaunchMail =

#ifdef WIN32
        VK_LAUNCH_MAIL
#else
        0
#endif
    ,

    LaunchApp2 =

#ifdef WIN32
        VK_LAUNCH_APP2
#else
        0
#endif
    ,

    Oem1 =

#ifdef WIN32
        VK_OEM_1
#else
        0
#endif
    ,

    OemPlus =

#ifdef WIN32
        VK_OEM_PLUS
#else
        0
#endif
    ,

    OemComma =

#ifdef WIN32
        VK_OEM_COMMA
#else
        0
#endif
    ,

    OemMinus =

#ifdef WIN32
        VK_OEM_MINUS
#else
        0
#endif
    ,

    OemPeriod =

#ifdef WIN32
        VK_OEM_PERIOD
#else
        0
#endif
    ,

    Oem2 =

#ifdef WIN32
        VK_OEM_2
#else
        0
#endif
    ,

    Oem3 =

#ifdef WIN32
        VK_OEM_3
#else
        0
#endif
    ,

    GamepadA =

#ifdef WIN32
        VK_GAMEPAD_A
#else
        0
#endif
    ,

    GamepadB =

#ifdef WIN32
        VK_GAMEPAD_B
#else
        0
#endif
    ,

    GamepadX =

#ifdef WIN32
        VK_GAMEPAD_X
#else
        0
#endif
    ,

    GamepadY =

#ifdef WIN32
        VK_GAMEPAD_Y
#else
        0
#endif
    ,

    GamepadRightShoulder =

#ifdef WIN32
        VK_GAMEPAD_RIGHT_SHOULDER
#else
        0
#endif
    ,

    GamepadLeftShoulder =

#ifdef WIN32
        VK_GAMEPAD_LEFT_SHOULDER
#else
        0
#endif
    ,

    GamepadLeftTrigger =

#ifdef WIN32
        VK_GAMEPAD_LEFT_TRIGGER
#else
        0
#endif
    ,

    GamepadRightTrigger =

#ifdef WIN32
        VK_GAMEPAD_RIGHT_TRIGGER
#else
        0
#endif
    ,

    GamepadDpadUp =

#ifdef WIN32
        VK_GAMEPAD_DPAD_UP
#else
        0
#endif
    ,

    GamepadDpadDown =

#ifdef WIN32
        VK_GAMEPAD_DPAD_DOWN
#else
        0
#endif
    ,

    GamepadDpadLeft =

#ifdef WIN32
        VK_GAMEPAD_DPAD_LEFT
#else
        0
#endif
    ,

    GamepadDpadRight =

#ifdef WIN32
        VK_GAMEPAD_DPAD_RIGHT
#else
        0
#endif
    ,

    GamepadMenu =

#ifdef WIN32
        VK_GAMEPAD_MENU
#else
        0
#endif
    ,

    GamepadView =

#ifdef WIN32
        VK_GAMEPAD_VIEW
#else
        0
#endif
    ,

    GamepadLeftThumbstickButton =

#ifdef WIN32
        VK_GAMEPAD_LEFT_THUMBSTICK_BUTTON
#else
        0
#endif
    ,

    GamepadRightThumbstickButton =

#ifdef WIN32
        VK_GAMEPAD_RIGHT_THUMBSTICK_BUTTON
#else
        0
#endif
    ,

    GamepadLeftThumbstickUp =

#ifdef WIN32
        VK_GAMEPAD_LEFT_THUMBSTICK_UP
#else
        0
#endif
    ,

    GamepadLeftThumbstickDown =

#ifdef WIN32
        VK_GAMEPAD_LEFT_THUMBSTICK_DOWN
#else
        0
#endif
    ,

    GamepadLeftThumbstickRight =

#ifdef WIN32
        VK_GAMEPAD_LEFT_THUMBSTICK_RIGHT
#else
        0
#endif
    ,

    GamepadLeftThumbstickLeft =

#ifdef WIN32
        VK_GAMEPAD_LEFT_THUMBSTICK_LEFT
#else
        0
#endif
    ,

    GamepadRightThumbstickUp =

#ifdef WIN32
        VK_GAMEPAD_RIGHT_THUMBSTICK_UP
#else
        0
#endif
    ,

    GamepadRightThumbstickDown =

#ifdef WIN32
        VK_GAMEPAD_RIGHT_THUMBSTICK_DOWN
#else
        0
#endif
    ,

    GamepadRightThumbstickRight =

#ifdef WIN32
        VK_GAMEPAD_RIGHT_THUMBSTICK_RIGHT
#else
        0
#endif
    ,

    GamepadRightThumbstickLeft =

#ifdef WIN32
        VK_GAMEPAD_RIGHT_THUMBSTICK_LEFT
#else
        0
#endif
    ,

    Oem4 =

#ifdef WIN32
        VK_OEM_4
#else
        0
#endif
    ,

    Oem5 =

#ifdef WIN32
        VK_OEM_5
#else
        0
#endif
    ,

    Oem6 =

#ifdef WIN32
        VK_OEM_6
#else
        0
#endif
    ,

    Oem7 =

#ifdef WIN32
        VK_OEM_7
#else
        0
#endif
    ,

    Oem8 =

#ifdef WIN32
        VK_OEM_8
#else
        0
#endif
    ,

    OemAx =

#ifdef WIN32
        VK_OEM_AX
#else
        0
#endif
    ,

    Oem102 =

#ifdef WIN32
        VK_OEM_102
#else
        0
#endif
    ,

    IcoHelp =

#ifdef WIN32
        VK_ICO_HELP
#else
        0
#endif
    ,

    Ico00 =

#ifdef WIN32
        VK_ICO_00
#else
        0
#endif
    ,

    ProcessKey =

#ifdef WIN32
        VK_PROCESSKEY
#else
        0
#endif
    ,

    IcoClear =

#ifdef WIN32
        VK_ICO_CLEAR
#else
        0
#endif
    ,

    Packet =

#ifdef WIN32
        VK_PACKET
#else
        0
#endif
    ,

    OemReset =

#ifdef WIN32
        VK_OEM_RESET
#else
        0
#endif
    ,

    OemJump =

#ifdef WIN32
        VK_OEM_JUMP
#else
        0
#endif
    ,

    OemPa1 =

#ifdef WIN32
        VK_OEM_PA1
#else
        0
#endif
    ,

    OemPa2 =

#ifdef WIN32
        VK_OEM_PA2
#else
        0
#endif
    ,

    OemPa3 =

#ifdef WIN32
        VK_OEM_PA3
#else
        0
#endif
    ,

    OemWsctrl =

#ifdef WIN32
        VK_OEM_WSCTRL
#else
        0
#endif
    ,

    OemCusel =

#ifdef WIN32
        VK_OEM_CUSEL
#else
        0
#endif
    ,

    OemAttn =

#ifdef WIN32
        VK_OEM_ATTN
#else
        0
#endif
    ,

    OemFinish =

#ifdef WIN32
        VK_OEM_FINISH
#else
        0
#endif
    ,

    OemCopy =

#ifdef WIN32
        VK_OEM_COPY
#else
        0
#endif
    ,

    OemAuto =

#ifdef WIN32
        VK_OEM_AUTO
#else
        0
#endif
    ,

    OemEnlw =

#ifdef WIN32
        VK_OEM_ENLW
#else
        0
#endif
    ,

    OemBacktab =

#ifdef WIN32
        VK_OEM_BACKTAB
#else
        0
#endif
    ,

    Attn =

#ifdef WIN32
        VK_ATTN
#else
        0
#endif
    ,

    Crsel =

#ifdef WIN32
        VK_CRSEL
#else
        0
#endif
    ,

    Exsel =

#ifdef WIN32
        VK_EXSEL
#else
        0
#endif
    ,

    Ereof =

#ifdef WIN32
        VK_EREOF
#else
        0
#endif
    ,

    Play =

#ifdef WIN32
        VK_PLAY
#else
        0
#endif
    ,

    Zoom =

#ifdef WIN32
        VK_ZOOM
#else
        0
#endif
    ,

    Noname =

#ifdef WIN32
        VK_NONAME
#else
        0
#endif
    ,

    Pa1 =

#ifdef WIN32
        VK_PA1
#else
        0
#endif
    ,

    OemClear =

#ifdef WIN32
        VK_OEM_CLEAR
#else
        0
#endif
    ,
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

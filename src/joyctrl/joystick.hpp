#pragma once

#include <cstdint>
#ifdef _WIN32
#include <windows.h>
#include <xinput.h>
#else
// linux stuff
#endif

#include <utility>

namespace joyctrl
{
// abstract representation of a joystick - both on windows and unix machines
enum class JoystickButton
{
    DPadUp =
#ifdef WIN32

        XINPUT_GAMEPAD_DPAD_UP
#else
        0
#endif
    ,
    DPadDown =
#ifdef WIN32

        XINPUT_GAMEPAD_DPAD_DOWN
#else
        0
#endif
    ,
    DPadLeft =
#ifdef WIN32

        XINPUT_GAMEPAD_DPAD_LEFT
#else
        0
#endif
    ,
    DPadRight =
#ifdef WIN32

        XINPUT_GAMEPAD_DPAD_RIGHT
#else
        0
#endif
    ,
    Start =
#ifdef WIN32

        XINPUT_GAMEPAD_START
#else
        0
#endif
    ,
    Back =
#ifdef WIN32

        XINPUT_GAMEPAD_BACK
#else
        0
#endif
    ,
    LS =
#ifdef WIN32

        XINPUT_GAMEPAD_LEFT_THUMB
#else
        0
#endif
    ,
    RS =
#ifdef WIN32

        XINPUT_GAMEPAD_RIGHT_THUMB
#else
        0
#endif
    ,
    LB =
#ifdef WIN32

        XINPUT_GAMEPAD_LEFT_SHOULDER
#else
        0
#endif
    ,
    RB =
#ifdef WIN32

        XINPUT_GAMEPAD_RIGHT_SHOULDER
#else
        0
#endif
    ,
    A =
#ifdef WIN32

        XINPUT_GAMEPAD_A
#else
        0
#endif
    ,
    B =
#ifdef WIN32

        XINPUT_GAMEPAD_B
#else
        0
#endif
    ,
    X =
#ifdef WIN32

        XINPUT_GAMEPAD_X
#else
        0
#endif
    ,
    Y =
#ifdef WIN32

        XINPUT_GAMEPAD_Y
#else
        0
#endif
    ,
};

// LT RT
using AnalogTriggerPair = std::pair<std::uint8_t, std::uint8_t>;

// LX LY, RX RY
using AnalogStickPair = std::pair<std::pair<short, short>, std::pair<short, short>>;

class Joystick
{
  public:
    Joystick(int index);

    bool isConnected() const;

    void refresh();

    bool isButtonPressed(JoystickButton button) const;

    AnalogTriggerPair getAnalogTriggers() const;
    AnalogStickPair getAnalogSticks() const;

  private:
    int mIndex;
    bool mConnected;
#ifdef _WIN32
    XINPUT_STATE mState;
#endif
};
} // namespace joyctrl

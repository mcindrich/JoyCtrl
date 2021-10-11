#pragma once

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
    DPadUp = XINPUT_GAMEPAD_DPAD_UP,
    DPadDown = XINPUT_GAMEPAD_DPAD_DOWN,
    DPadLeft = XINPUT_GAMEPAD_DPAD_LEFT,
    DPadRight = XINPUT_GAMEPAD_DPAD_RIGHT,
    Start = XINPUT_GAMEPAD_START,
    Back = XINPUT_GAMEPAD_BACK,
    LS = XINPUT_GAMEPAD_LEFT_THUMB,
    RS = XINPUT_GAMEPAD_RIGHT_THUMB,
    LB = XINPUT_GAMEPAD_LEFT_SHOULDER,
    RB = XINPUT_GAMEPAD_RIGHT_SHOULDER,
    A = XINPUT_GAMEPAD_A,
    B = XINPUT_GAMEPAD_B,
    X = XINPUT_GAMEPAD_X,
    Y = XINPUT_GAMEPAD_Y,
};

// LT RT
using AnalogTriggerPair = std::pair<byte, byte>;

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

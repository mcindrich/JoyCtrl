#include <joyctrl/joystick.hpp>

namespace joyctrl
{
Joystick::Joystick(int index) : mIndex(index)
{
#ifdef _WIN32
    ZeroMemory(&mState, sizeof(mState));
    mConnected = (XInputGetState(mIndex, &mState) == ERROR_SUCCESS);
#else
    // linux
#endif
}

bool Joystick::isConnected() const
{
    return mConnected;
}

bool Joystick::isButtonPressed(JoystickButton button) const
{
    bool pressed = false;

#ifdef _WIN32
    pressed = (mState.Gamepad.wButtons & (unsigned long)button) != 0;
#else
#endif

    return pressed;
}

AnalogTriggerPair Joystick::getAnalogTriggers() const
{
    AnalogTriggerPair tp;

#ifdef _WIN32
    tp = std::make_pair(mState.Gamepad.bLeftTrigger, mState.Gamepad.bRightTrigger);
#else
#endif

    return tp;
}

AnalogStickPair Joystick::getAnalogSticks() const
{
    AnalogStickPair ap;
#ifdef _WIN32
    ap = std::make_pair(std::make_pair(mState.Gamepad.sThumbLX, mState.Gamepad.sThumbLY), std::make_pair(mState.Gamepad.sThumbRX, mState.Gamepad.sThumbRY));
#else
#endif
    return ap;
}

void Joystick::refresh()
{
#ifdef _WIN32
    ZeroMemory(&mState, sizeof(mState));
    mConnected = (XInputGetState(mIndex, &mState) == ERROR_SUCCESS);
#else
    // linux
#endif
}
}
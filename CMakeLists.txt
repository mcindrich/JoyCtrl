cmake_minimum_required(VERSION 3.0.0)
project(JoyCtrl VERSION 1.0.0)

# cxx std
set(CMAKE_CXX_STANDARD 17)

# libs
find_package(toml11 CONFIG REQUIRED)
find_package(argparse CONFIG REQUIRED)

# includes
include_directories(
    "src"
    "dependencies/UJoy-cpp/src"
    "dependencies/UJoy-cpp/deps/UJoy/src"
)

link_directories(
    "dependencies/UJoy-cpp/build"
    "dependencies/UJoy-cpp/deps/UJoy/build"
)

add_executable(
    ${CMAKE_PROJECT_NAME}
    
    "src/joyctrl.cpp"
    "src/joyctrl/log.cpp"
    
    "src/joyctrl/joystick_handler.cpp" 
    
    "src/joyctrl/configuration.cpp" 
    "src/joyctrl/configuration/application_configuration.cpp" 
    
    "src/joyctrl/configuration/button_combination.cpp" 
    
    "src/joyctrl/configuration/action_parser.cpp" 
    "src/joyctrl/foreground_window.cpp"

    "src/joyctrl/configuration/action/key_down.cpp"
)

if(WIN32)
target_link_libraries(
    ${CMAKE_PROJECT_NAME}
    argparse::argparse xinput UJoy++ UJoy
)
elseif(UNIX)
target_link_libraries(
    ${CMAKE_PROJECT_NAME}
    argparse::argparse toml11::toml11 UJoy++ UJoy
)
endif()

target_compile_definitions(
    ${CMAKE_PROJECT_NAME}
    PUBLIC
    VERSION_MAJOR=1
    VERSION_MINOR=0
)

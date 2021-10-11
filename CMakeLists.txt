cmake_minimum_required(VERSION 3.0.0)
project(JoyCtrl VERSION 1.0.0)

# cxx std
set(CMAKE_CXX_STANDARD 17)

# libs
find_package(nlohmann_json CONFIG REQUIRED)
find_package(argparse CONFIG REQUIRED)

# includes
include_directories(
    "src"
)

add_executable(
    ${CMAKE_PROJECT_NAME}
    
    "src/joyctrl.cpp"
    "src/joyctrl/log.cpp"
    "src/joyctrl/joystick_handler.hpp" 
    "src/joyctrl/joystick_handler.cpp" 
    "src/joyctrl/configuration.hpp" 
    "src/joyctrl/configuration/application_configuration.hpp" 
    "src/joyctrl/configuration.cpp" 
    "src/joyctrl/configuration/application_configuration.cpp" 
    "src/joyctrl/configuration/button_configuration.hpp" 
    "src/joyctrl/configuration/button_combination.hpp" 
    "src/joyctrl/configuration/button_combination.cpp" 
    "src/joyctrl/configuration/action.hpp" 
    "src/joyctrl/configuration/action_parser.hpp" 
    "src/joyctrl/configuration/action_parser.cpp" 
    "src/joyctrl/joystick.cpp"
    "src/joyctrl/foreground_window.cpp"
 )

if(WIN32)
target_link_libraries(
    ${CMAKE_PROJECT_NAME}
    PRIVATE nlohmann_json nlohmann_json::nlohmann_json argparse::argparse xinput
)
elseif(UNIX)
target_link_libraries(
    ${CMAKE_PROJECT_NAME}
    PRIVATE nlohmann_json nlohmann_json::nlohmann_json argparse::argparse
)
endif()

target_compile_definitions(
    ${CMAKE_PROJECT_NAME}
    PUBLIC
    VERSION_MAJOR=1
    VERSION_MINOR=0
)

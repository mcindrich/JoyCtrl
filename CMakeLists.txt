cmake_minimum_required(VERSION 3.0.0)
project(JoyCtrl VERSION 1.0.0)

# cxx std
set(CMAKE_CXX_STANDARD 20)

# libs
find_package(nlohmann_json CONFIG REQUIRED)
find_package(toml11 CONFIG REQUIRED)
find_package(argparse CONFIG REQUIRED)

# includes
include_directories(
    "src"
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
    "src/joyctrl/joystick.cpp"
    "src/joyctrl/foreground_window.cpp"
      
      
      "src/joyctrl/configuration/action/key_down.cpp"
)

if(WIN32)
target_link_libraries(
    ${CMAKE_PROJECT_NAME}
    PRIVATE nlohmann_json nlohmann_json::nlohmann_json argparse::argparse xinput
)
elseif(UNIX)
target_link_libraries(
    ${CMAKE_PROJECT_NAME}
    PRIVATE nlohmann_json nlohmann_json::nlohmann_json argparse::argparse toml11::toml11
)
endif()

target_compile_definitions(
    ${CMAKE_PROJECT_NAME}
    PUBLIC
    VERSION_MAJOR=1
    VERSION_MINOR=0
)

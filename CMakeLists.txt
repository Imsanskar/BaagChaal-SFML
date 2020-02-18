cmake_minimum_required(VERSION 3.15)
project(BaagChaal-SFML)

set(source includes/MainMenu.h src/Mainmenu.cpp includes/Loadboard.h src/LoadBoard.cpp includes/tigers.h src/tigers.cpp includes/goats.h src/goats.cpp includes/Game.h src/Game.cpp includes/Cell.h src/Cell.cpp)
add_executable(BaagChaal_SFML main.cpp ${source})
include_directories(BaagChaal-SFML includes)
set(CMAKE_CXX_STANDARD 17)

target_link_libraries (BaagChaal_SFML sfml-graphics sfml-window sfml-system)

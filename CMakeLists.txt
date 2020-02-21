cmake_minimum_required(VERSION 3.15)
project(BaagChaal-SFML)

set(CMAKE_CXX_STANDARD 14)
set(source includes/MainMenu.h src/Mainmenu.cpp includes/Loadboard.h src/LoadBoard.cpp includes/tigers.h src/tigers.cpp includes/goats.h src/goats.cpp includes/Game.h src/Game.cpp includes/Cell.h src/Cell.cpp includes/Piece.h src/Piece.cpp)
add_executable(BaagChaal-SFML main.cpp ${source})

include_directories("C:/SFML/include")
link_directories("C:/SFML/lib")
find_package(SFML 2.5.1 COMPONENTS system window graphics audio network)

target_link_libraries(BaagChaal-SFML sfml-graphics sfml-window sfml-network sfml-audio sfml-system)


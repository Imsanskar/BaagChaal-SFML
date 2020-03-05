cmake_minimum_required(VERSION 3.10)
project(Baagchaal)

set(CMAKE_CXX_STANDARD 14)
set(source includes/MainMenu.h src/Mainmenu.cpp includes/Loadboard.h src/LoadBoard.cpp includes/tigers.h src/tigers.cpp includes/goats.h src/goats.cpp includes/Game.h src/Game.cpp includes/Cell.h src/Cell.cpp src/quitGame.cpp includes/quitGame.h src/Piece.cpp includes/Piece.h includes/AI.h src/AI.cpp)
add_executable(Baagchaal main.cpp ${source})


target_link_libraries(Baagchaal sfml-graphics sfml-window sfml-network sfml-audio sfml-system)
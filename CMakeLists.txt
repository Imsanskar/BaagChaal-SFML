cmake_minimum_required(VERSION 3.15)
project(Baagchaal)


set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
if ( ${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR} )
    message( FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there. You may need to remove CMakeCache.txt." )
endif()

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(source includes/MainMenu.h src/Mainmenu.cpp includes/Loadboard.h src/LoadBoard.cpp includes/tigers.h src/tigers.cpp includes/goats.h src/goats.cpp includes/Game.h src/Game.cpp includes/Cell.h src/Cell.cpp src/quitGame.cpp includes/quitGame.h src/Piece.cpp includes/Piece.h)
add_executable(Baagchaal main.cpp ${source})


if(SFML_FOUND)
    include_directories("C:/SFML/include")
    link_directories("C:/SFML/lib")
    find_package(SFML 2.5.1 COMPONENTS system window graphics audio network)
endif()

target_link_libraries(Baagchaal sfml-graphics sfml-window sfml-network sfml-audio sfml-system)
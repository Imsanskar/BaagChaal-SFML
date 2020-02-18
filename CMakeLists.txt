cmake_minimum_required(VERSION 3.15)
project(BaagChaal-SFML)

set(source includes/MainMenu.h src/Mainmenu.cpp includes/Loadboard.h src/LoadBoard.cpp includes/tigers.h src/tigers.cpp includes/goats.h src/goats.cpp includes/Game.h src/Game.cpp includes/Cell.h src/Cell.cpp)
add_executable(BaagChaal_SFML main.cpp ${source})
include_directories(BaagChaal-SFML includes)
set(CMAKE_CXX_STANDARD 17)

set(SFML_STATIC_LIBRARIES TRUE)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_DEPENDENCIES})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()
find_library(SFML 2.5.1 COMPONENTS system window graphics audio REQUIRED)



target_link_libraries (BaagChaal_SFML sfml-graphics sfml-window sfml-system)

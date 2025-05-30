cmake_minimum_required(VERSION 3.15)
project(TetrisGame)

set(SFML_DIR ${CMAKE_SOURCE_DIR}/SFML-2.6.0)

file(GLOB CPPS "src/*.cpp")
file(GLOB HPPS "include/*.hpp")

add_executable(Tetris
    ${CPPS}
    ${HPPS}
)

set(LIBS
    sfml-graphics
    sfml-window
    sfml-system
)

if(WIN32)
    set(LIBS sfml-main ${LIBS})
endif(WIN32)

target_link_libraries(Tetris
    ${LIBS}
)
target_include_directories(Tetris PRIVATE "include")

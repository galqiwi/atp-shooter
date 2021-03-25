cmake_minimum_required(VERSION 3.8)

project(atp-shooter)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)


include_directories(${CMAKE_SOURCE_DIR})

#add_custom_command(
#        OUTPUT ${CMAKE_BINARY_DIR}/test.cfg
#        COMMAND cp ${PROJECT_SOURCE_DIR}/maps/test.cfg ${CMAKE_BINARY_DIR}/test.cfg
#        DEPENDS ${PROJECT_SOURCE_DIR}/maps/test.cfg
#)

#add_custom_target(CopyMaps DEPENDS ${CMAKE_BINARY_DIR}/test.cfg)

file(DOWNLOAD https://galqiwi.ru/atp-shooter/SFML-2.5.1-linux-gcc-64-bit.tar.gz ${CMAKE_SOURCE_DIR}/sfml.tar.gz)
execute_process(
        COMMAND ${CMAKE_COMMAND} -E tar xzf sfml.tar.gz
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

include_directories(${CMAKE_SOURCE_DIR}/SFML-2.5.1/include)
link_directories(${CMAKE_SOURCE_DIR}/SFML-2.5.1/lib)


add_executable(atp-shooter ${PROJECT_SOURCE_DIR}/src/main.cpp ${PROJECT_SOURCE_DIR}/src/Vector2D.cpp src/Scene.cpp src/Scene.h src/GraphicsProxy.cpp src/GraphicsProxy.h)

target_link_libraries(atp-shooter sfml-system sfml-graphics sfml-window)
#add_dependencies(atp-shooter CopyMaps)
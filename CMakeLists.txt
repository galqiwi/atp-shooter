cmake_minimum_required(VERSION 3.8)

project(atp-shooter)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)


include_directories(${CMAKE_SOURCE_DIR})

file(DOWNLOAD https://galqiwi.ru/atp-shooter/SFML-2.5.1-linux-gcc-64-bit.tar.gz ${CMAKE_SOURCE_DIR}/sfml.tar.gz)
execute_process(
        COMMAND ${CMAKE_COMMAND} -E tar xzf sfml.tar.gz
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

include_directories(${CMAKE_SOURCE_DIR}/SFML-2.5.1/include)
link_directories(${CMAKE_SOURCE_DIR}/SFML-2.5.1/lib)


add_executable(atp-shooter ${PROJECT_SOURCE_DIR}/src/main.cpp ${PROJECT_SOURCE_DIR}/src/Vector2D.cpp src/Scene.cpp src/Scene.h src/GraphicsFacade.cpp src/GraphicsFacade.h src/Entity.cpp src/Entity.h src/Player.cpp src/Player.h src/Texture.cpp src/Texture.h src/GraphicsEngine.cpp src/GraphicsEngine.h src/constants.h src/EnemySpawner.cpp src/EnemySpawner.h src/EntitySpawner.cpp src/EntitySpawner.h src/FireballSpawner.cpp src/FireballSpawner.h src/InputCommand.cpp src/InputCommand.h src/InputCommandDecorator.cpp src/InputCommandDecorator.h src/SaveDecorator.cpp src/SaveDecorator.h src/LoadDecorator.cpp src/LoadDecorator.h src/WalkCommand.cpp src/WalkCommand.h)

set_property(TARGET atp-shooter PROPERTY CXX_STANDARD 17)

target_link_libraries(atp-shooter sfml-system sfml-graphics sfml-window)

set_target_properties(atp-shooter PROPERTIES INSTALL_RPATH $ORIGIN/../lib)
install(TARGETS atp-shooter)
install(CODE "file(COPY ${PROJECT_SOURCE_DIR}/SFML-2.5.1/lib DESTINATION ${CMAKE_INSTALL_PREFIX}/)")

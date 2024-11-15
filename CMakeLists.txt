cmake_minimum_required(VERSION 3.28)
project(LightYears VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD          20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

set(LIGHT_YEARS_GAME_ENGINE_TARGET_NAME LightYearsEngine)
set(LIGHT_YEARS_GAME_TARGET_NAME LightYearsGame)

add_subdirectory(LightYearsEngine)
add_subdirectory(LightYearsGame)

find_package(SFML 2.6.1 COMPONENTS system window graphics network audio REQUIRED)
target_link_libraries(${LIGHT_YEARS_GAME_ENGINE_TARGET_NAME} PUBLIC sfml-system sfml-window sfml-graphics sfml-network sfml-audio
)




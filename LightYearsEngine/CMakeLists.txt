add_library(${LIGHT_YEARS_GAME_ENGINE_TARGET_NAME} STATIC
            ${CMAKE_CURRENT_SOURCE_DIR}/src/frame/Application.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/src/EntryPoint.cpp

            ${CMAKE_CURRENT_SOURCE_DIR}/include/frame/Application.h
            ${CMAKE_CURRENT_SOURCE_DIR}/include/EntryPoint.h

            ${CMAKE_CURRENT_SOURCE_DIR}/include/frame/Core.h
            ${CMAKE_CURRENT_SOURCE_DIR}/src/frame/Core.cpp
)

target_include_directories(${LIGHT_YEARS_GAME_ENGINE_TARGET_NAME} PUBLIC
                           ${CMAKE_CURRENT_SOURCE_DIR}/include
)
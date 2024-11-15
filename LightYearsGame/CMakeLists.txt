add_executable(${LIGHT_YEARS_GAME_TARGET_NAME}
               ${CMAKE_CURRENT_SOURCE_DIR}/SourceFiles/GameApplication.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/HeaderFiles/GameApplication.h
)

target_include_directories(${LIGHT_YEARS_GAME_TARGET_NAME} PUBLIC
                           ${CMAKE_CURRENT_SOURCE_DIR}/HeaderFiles
)

target_link_libraries(${LIGHT_YEARS_GAME_TARGET_NAME} PUBLIC
                      ${LIGHT_YEARS_GAME_ENGINE_TARGET_NAME}
)
add_executable(${LIGHT_YEARS_GAME_TARGET_NAME}
        ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/frame/Application.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/frame/Application.cpp
)

target_include_directories(${LIGHT_YEARS_GAME_TARGET_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${LIGHT_YEARS_GAME_TARGET_NAME} PUBLIC sfml-graphics)
target_link_libraries(${LIGHT_YEARS_GAME_TARGET_NAME} PUBLIC sfml-window)
target_link_libraries(${LIGHT_YEARS_GAME_TARGET_NAME} PUBLIC sfml-system)
target_link_libraries(${LIGHT_YEARS_GAME_TARGET_NAME} PUBLIC sfml-audio)
target_link_libraries(${LIGHT_YEARS_GAME_TARGET_NAME} PUBLIC sfml-network)

function(CopyLibToTarget LIB_NAME TARGET_NAME)
    add_custom_command(TARGET ${TARGET_NAME}
            POST_BUILD
            COMMAND
            ${CMAKE_COMMAND} -E copy-if-different
            $<TARGET_FILE:${LIB_NAME}>
            $<TARGET_FILE_DIR:${TARGET_NAME}>
    )
endfunction()

CopyLibToTarget(sfml-network ${LIGHT_YEARS_GAME_TARGET_NAME})
CopyLibToTarget(sfml-graphics ${LIGHT_YEARS_GAME_TARGET_NAME})
CopyLibToTarget(sfml-window ${LIGHT_YEARS_GAME_TARGET_NAME})
CopyLibToTarget(sfml-system ${LIGHT_YEARS_GAME_TARGET_NAME})
CopyLibToTarget(sfml-audio ${LIGHT_YEARS_GAME_TARGET_NAME})

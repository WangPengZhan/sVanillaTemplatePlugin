set(TestTarget TemplatePlugin)
set(PluginTest ${TestTarget}_test)
file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)
set(SOURCES ${TEST_SOURCES})

find_package(GTest CONFIG REQUIRED)

enable_testing()


include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/..
)

add_executable(${PluginTest} ${SOURCES})
set_target_properties(${PluginTest} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY $<TARGET_FILE_DIR:${TestTarget}>
)
add_test(NAME ${PluginTest} COMMAND ${PluginTest})

if (NOT TARGET spdlog)
    set(SPDLOG_BUILD_SHARED ON CACHE BOOL "Build spdlog as a shared library")
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../ThirdParty/spdlog)
endif()

target_include_directories(${PluginTest}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../src
        ${CMAKE_CURRENT_SOURCE_DIR}/../ThirdParty/spdlog
        ${CMAKE_CURRENT_SOURCE_DIR}/../ThirdParty/sVanillaPluginCommon/PluginCommon
        ${CMAKE_CURRENT_SOURCE_DIR}/../ThirdParty/sVanillaPluginCommon
)

target_link_libraries(${PluginTest}
    PRIVATE
        ${TestTarget}
        GTest::gtest_main 
)

add_custom_command(TARGET ${PluginTest}
    POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:spdlog> $<TARGET_FILE_DIR:${PluginTest}>
        COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:FFmpeg> $<TARGET_FILE_DIR:${PluginTest}>
        COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:${TestTarget}> $<TARGET_FILE_DIR:${PluginTest}>
)
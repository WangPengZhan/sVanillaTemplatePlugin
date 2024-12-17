set(TemplatePlugin_test TemplatePlugin_test)
file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)
set(SOURCES ${TEST_SOURCES} ${TESTED_SOURCES} ${TESTED_DEPANDED_SOURCES})

find_package(GTest CONFIG REQUIRED)

enable_testing()


include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/..
)

add_executable(${TemplatePlugin_test} ${SOURCES})
add_test(NAME ${TemplatePlugin_test} COMMAND ${TemplatePlugin_test})

target_include_directories(${TemplatePlugin_test}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../src
        ${CMAKE_CURRENT_SOURCE_DIR}/../ThirdParty/spdlog
        ${CMAKE_CURRENT_SOURCE_DIR}/../ThirdParty/sVanillaPluginCommon/include
)

target_link_libraries(${TemplatePlugin_test}
    PRIVATE
        TemplatePlugin
        GTest::gtest 
        GTest::gmock 
        GTest::gtest_main 
        GTest::gmock_main
)
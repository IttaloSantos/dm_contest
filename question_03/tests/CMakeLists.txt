include_directories("${PROJECT_SOURCE_DIR}/googletest/include")

add_executable(testCases
    testCases.cpp
)

target_link_libraries(testCases
    PRIVATE
    gtest
    EventHandler
)

include(GoogleTest)
gtest_discover_tests(testCases)
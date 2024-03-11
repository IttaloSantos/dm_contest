# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(testCases
    testCases.cpp
)

target_link_libraries(testCases
    PRIVATE
    EventHandler
    ${GTEST_LIBRARIES}
    pthread
)

include(GoogleTest)
gtest_discover_tests(testCases)
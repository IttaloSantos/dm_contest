add_library(correct_function
    correct_function.cpp
)

target_include_directories(correct_function
    PUBLIC
    "${PROJECT_SOURCE_DIR}/src/inc"
)

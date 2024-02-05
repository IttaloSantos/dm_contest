add_library(original_function
    original_function.cpp
)

target_include_directories(original_function
    PUBLIC
    "${PROJECT_SOURCE_DIR}/src/inc"
)

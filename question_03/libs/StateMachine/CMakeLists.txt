add_library(StateMachine
    StateMachine.cpp
)

target_include_directories(StateMachine
    PUBLIC
    "./inc"
    "${PROJECT_SOURCE_DIR}/libs/inc"
)
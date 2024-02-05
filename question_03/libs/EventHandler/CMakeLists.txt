add_library(EventHandler
    EventHandler.cpp
)

target_link_libraries(EventHandler
    PRIVATE
    StateMachine
    Action
)

target_include_directories(EventHandler
    PUBLIC
    "./inc"
    "${PROJECT_SOURCE_DIR}/libs/inc"
    "${PROJECT_SOURCE_DIR}/libs/StateMachine/inc"
    "${PROJECT_SOURCE_DIR}/libs/Action/inc"
)
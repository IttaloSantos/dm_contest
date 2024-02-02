add_executable(app 
    app.cpp
)

target_link_libraries(app 
    PRIVATE
    original_function
    correct_function
)
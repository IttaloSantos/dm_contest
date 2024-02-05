set(EXAMPLES 
    normal 
    link_down 
    package_error
    timeout
    invalid_states
)

foreach(FILE ${EXAMPLES})
    add_executable(${FILE}
        ${FILE}.cpp
    )
    target_link_libraries(${FILE}
        PRIVATE
        EventHandler
    )
endforeach()
# look for ccache and include it
message(STATUS "Looking for ccache")
find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
    message(STATUS "ccache found in: ${CCACHE_FOUND}")
else()
    message(STATUS "ccache not found")
endif()

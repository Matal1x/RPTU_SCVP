cmake_minimum_required(VERSION 3.10)

project(Exercise3)

add_executable(exercise3_v2
    main.cpp
    state_machine.cpp
    stimuli.cpp
)

target_include_directories(exercise3_v2
    PRIVATE $ENV{SYSTEMC_HOME}/include/
)

find_library(SYSTEMC_LIBRARY 
    NAMES systemc
    PATHS $ENV{SYSTEMC_HOME}/lib-$ENV{SYSTEMC_TARGET_ARCH}/
)

target_link_libraries(exercise3_v2
    PRIVATE ${SYSTEMC_LIBRARY}
)

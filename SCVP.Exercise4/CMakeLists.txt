cmake_minimum_required(VERSION 3.10)

project(Exercise4)

add_executable(exercise4_v5
    main.cpp
)

target_include_directories(exercise4_v5
    PRIVATE $ENV{SYSTEMC_HOME}/include/
)

find_library(SYSTEMC_LIBRARY 
    NAMES systemc
    PATHS $ENV{SYSTEMC_HOME}/lib-$ENV{SYSTEMC_TARGET_ARCH}/
)

target_link_libraries(exercise4_v5
    PRIVATE ${SYSTEMC_LIBRARY}
)

add_executable(fifo_example
    main.cpp
    consumer.cpp
    consumer.h
    producer.cpp
    producer.h
)

target_include_directories(fifo_example
PRIVATE $ENV{SYSTEMC_HOME}/include/
)

target_link_libraries(fifo_example
    PRIVATE ${SYSTEMC_LIBRARY}
)
find_library(SYSTEMC_LIBRARY 
    NAMES systemc
    PATHS $ENV{SYSTEMC_HOME}/lib-$ENV{SYSTEMC_TARGET_ARCH}/
)

target_link_libraries(fifo_example
    PRIVATE ${SYSTEMC_LIBRARY}
)


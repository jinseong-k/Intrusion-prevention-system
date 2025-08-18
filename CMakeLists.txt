PROJECT(NIPS_Sample)
CMAKE_MINIMUM_REQUIRED(VERSION 3.25)


INCLUDE_DIRECTORIES(src)
#LINK_DIRECTORIES()
#LINK_LIBRARIES(pthread)
ADD_EXECUTABLE(run
    src/main.c
    src/init_env.c
    src/thr_manager.c
    src/pkt_reader.c
    src/ips_util.c
    )
TARGET_LINK_LIBRARIES(run pthread)
ADD_COMPILE_OPTIONS(-Wall -Wextra)

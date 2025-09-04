PROJECT(NIPS_Sample)
CMAKE_MINIMUM_REQUIRED(VERSION 3.25)


INCLUDE_DIRECTORIES(src 
    lib/gotouniverse/clang/src/libcommon/)
LINK_DIRECTORIES(lib)
#LINK_LIBRARIES(pthread)
ADD_EXECUTABLE(run
    src/main.c
    src/init_env.c
    src/thr_manager.c
    src/pkt_reader.c
    src/ips_util.c
    src/pkt_decoder.c
    )
TARGET_LINK_LIBRARIES(run pthread common pcap)
ADD_COMPILE_OPTIONS(-Wall -Wextra)

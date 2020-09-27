cmake_minimum_required(VERSION 3.7)
project(FirstAIFramework)
set(CMAKE_CXX_STANDARD 11)

link_directories("/usr/lib/" "/home/mxc/armadillo-8.300.4/build" "/usr/lib/x86_64-linux-gnu" "/lib/i386-linux-gnu/")
include_directories("/usr/include/armadillo_bits/" "/usr/include") # <<<

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES main.cpp src/TestHello.cpp src/TestHello.h layer/MyLayer.h layer/MyLayer.cpp src/JsonReaderFile.h src/JsonReaderFile.cpp)
set(PROTOBUF_LIBRARY /usr/local/protobuf/lib/libprotobuf.so)
include(FindProtobuf)
find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIR})



add_executable(FirstAIFramework ${SOURCE_FILES})
target_link_libraries(FirstAIFramework jsoncpp)
target_link_libraries(FirstAIFramework armadillo)
target_link_libraries(FirstAIFramework ${PROTOBUF_LIBRARY})
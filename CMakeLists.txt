cmake_minimum_required(VERSION 3.7)
project(FirstAIFramework)

set(CMAKE_CXX_STANDARD 11)

include(FindProtobuf)

find_package(PkgConfig REQUIRED)
find_package(Armadillo REQUIRED)
find_package(Protobuf REQUIRED)

include_directories(${PROTOBUF_INCLUDE_DIR})
include_directories(layer)
include_directories(networkDefine)
include_directories(src)
include_directories(${ARMADILLO_INCLUDE_DIRS})

pkg_check_modules(JSONCPP jsoncpp)
link_libraries(${JSONCPP_LIBRARIES})

add_executable(FirstAIFramework
        layer/MyLayer.cpp
        layer/MyLayer.h
        networkDefine/layerParamDefine.h
        networkDefine/netParamDefine.h
        src/JsonReaderFile.cpp
        src/JsonReaderFile.h
        CMakeLists.txt
        main.cpp
        README.md layer/LayerBlob.h layer/LayerBlob.cpp layer/readData.h layer/readData.cpp)

target_link_libraries(FirstAIFramework ${JSONCPP_LIBRARIES})
target_link_libraries(FirstAIFramework -larmadillo)
target_link_libraries(FirstAIFramework ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${PROTOBUF_LIBRARY})


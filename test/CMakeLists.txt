cmake_minimum_required(VERSION 3.24)
project(Test)

set(CMAKE_CXX_STANDARD 17)

# 查找 protobuf
find_package(Protobuf REQUIRED)

# 头文件路径
include_directories(${Protobuf_INCLUDE_DIRS})

aux_source_directory(./ SRC)

add_executable(test ${SRC})

# 连接 protobuf 库
target_link_libraries(test ${Protobuf_LIBRARIES})
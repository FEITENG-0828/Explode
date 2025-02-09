# 指定 CMake 的最低版本要求
cmake_minimum_required(VERSION 3.10)

# 定义项目名称和使用的语言
project(Explode LANGUAGES CXX)

# 指定 C++ 编译器为 g++
set(CMAKE_CXX_COMPILER "g++")
# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 添加头文件目录
include_directories(${PROJECT_SOURCE_DIR}/inc)

# 添加源文件目录
aux_source_directory(src SOURCES)

# 定义可执行文件输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# 创建可执行文件
add_executable(${PROJECT_NAME} ${SOURCES})

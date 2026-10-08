cmake_minimum_required(VERSION 3.16)
project(Threadtest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(Threadtest main.cpp threadpool.cpp)

# 用了 std::condition_variable / std::thread，必须链接 Threads::Threads，
# 否则在 Linux 上会报 undefined reference to pthread_cond_clockwait。
find_package(Threads REQUIRED)
target_link_libraries(Threadtest PRIVATE Threads::Threads)



cmake_minimum_required(VERSION 3.20.0)
project(c3)

add_executable(c3
        c3/main.cpp
        c3/utils/Str.cpp
        c3/school/grade.cpp
        c3/school/Core.cpp
        c3/school/Student.cpp
        c3/school/Grad.cpp)

target_include_directories(c3 PRIVATE .)

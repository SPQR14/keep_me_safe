cmake_minimum_required(VERSION 3.17)
project(keep_me_safe)

set(CMAKE_CXX_STANDARD 14)

include_directories(C)

add_executable(keep_me_safe
        C/enciption.c
        C/enciption.h
        LICENSE)

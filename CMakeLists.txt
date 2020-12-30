cmake_minimum_required(VERSION 3.17)
project(keep_me_safe)

set(CMAKE_CXX_STANDARD 14)

include_directories(C)

add_executable(keep_me_safe
        LICENSE C/AES/aes.h C/AES/aes.c C/AES/aes_run.c C/DES/des.c C/DES/des.h C/DES/run_des.c)

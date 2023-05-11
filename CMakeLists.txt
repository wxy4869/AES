cmake_minimum_required(VERSION 3.22)
project(AES)

set(CMAKE_CXX_STANDARD 14)

add_executable(AES main.cpp cipher.cpp cipher.h xtime.cpp xtime.h key_expansion.cpp key_expansion.h inv_cipher.cpp inv_cipher.h)

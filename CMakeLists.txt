cmake_minimum_required(VERSION 3.21)

project(aoe2_re LANGUAGES C CXX ASM)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 32-bit x86 build is required for 1:1 binary compat with the original PE32 exe
if(NOT CMAKE_SYSTEM_PROCESSOR MATCHES "(x86)|(X86)|(i.86)")
    message(WARNING
        "aoe2_re must be compiled as 32-bit x86 to match the original binary. "
        "Configure with a cross toolchain (e.g. clang -m32 / i686-w64-mingw32). "
        "Apple Silicon hosts: use a cross-compiler, do not build arm64.")
endif()

add_subdirectory(Source)
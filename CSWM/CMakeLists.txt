cmake_minimum_required(VERSION 3.5)

project(CSWM)

if(NOT WIN32)
set(POSTFIX "_i386")
set(CMAKE_CXX_FLAGS "-m32")
set(CMAKE_SHARED_LINKER_FLAGS "-m32")
endif()

add_definitions(-DHAVE_STDINT_H -D_CRT_SECURE_NO_WARNINGS)

add_library(CSWM SHARED
    182/AMXX.cpp
    Module.cpp
    CSWM.cpp
    HEFW.cpp
    FakeCMD.cpp
)

target_include_directories(CSWM PUBLIC
    ${PROJECT_SOURCE_DIR}/.
    ${PROJECT_SOURCE_DIR}/../SDK/metamod/
    ${PROJECT_SOURCE_DIR}/../SDK/cssdk
)

set_target_properties(CSWM PROPERTIES
    OUTPUT_NAME cswm_amxx${POSTFIX}
)

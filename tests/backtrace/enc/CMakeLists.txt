# Copyright (c) Microsoft Corporation. All rights reserved.
# Licensed under the MIT License.

include(add_enclave_executable)

add_executable(backtrace_enc enc.cpp)

if(USE_DEBUG_MALLOC)
    target_compile_definitions(backtrace_enc PRIVATE OE_USE_DEBUG_MALLOC)
endif()

target_link_libraries(backtrace_enc oelibcxx oeenclave)

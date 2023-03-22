cmake_minimum_required(VERSION 3.15)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)
set(D_GLIBCXX_USE_CXX11_ABI 1)

# fix "unable to disambiguate: -search_paths_first"
IF ( NOT DEFINED HAVE_FLAG_SEARCH_PATHS_FIRST )
    SET(HAVE_FLAG_SEARCH_PATHS_FIRST 0)
    IF ( "${DARWIN_MAJOR_VERSION}" GREATER 6 )
        SET(HAVE_FLAG_SEARCH_PATHS_FIRST 1)
    ENDIF ()
ENDIF ()

project(Dobby)


set(assembler.source
        # logging
        external/logging/logging.cc

        # assembler
        source/core/assembler/assembler.cc
        source/core/assembler/assembler-arm.cc
        source/core/assembler/assembler-arm64.cc
        source/core/assembler/assembler-ia32.cc
        source/core/assembler/assembler-x64.cc

        # codegen
        source/core/codegen/codegen-arm.cc
        source/core/codegen/codegen-arm64.cc
        source/core/codegen/codegen-ia32.cc
        source/core/codegen/codegen-x64.cc

        # memory kit
        source/MemoryAllocator/CodeBuffer/CodeBufferBase.cc
        )

add_library(assembler STATIC
        ${assembler.source}
        )

add_executable(demo1
        examples/main.cc
        ${assembler.source}
        )




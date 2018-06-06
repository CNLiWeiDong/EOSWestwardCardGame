cmake_minimum_required(VERSION 3.9)
project(templet CXX)


set(EOSIO_INSTALL_DIR /usr/local)
set(BOOST_INCLUDE_DIR /usr/local/include)
set(WASM_INSTALL_DIR /usr/local/wasm)
set(S2WASM_PATH ${EOSIO_INSTALL_DIR}/bin/eosio-s2wasm)
set(WASTS2WASM_PATH ${EOSIO_INSTALL_DIR}/bin/eosio-wast2wasm)
set(ABIGEN ${EOSIO_INSTALL_DIR}/bin/eosio-abigen)
set(EOSIO_CONTRACTSDK_PATH ${EOSIO_INSTALL_DIR}/usr/share/eosio/contractsdk)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -emit-llvm")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++14")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --target=wasm32")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -nostdinc")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -nostdlib")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -nostdlibinc")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ffreestanding")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-threadsafe-statics")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-exceptions")

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${EOSIO_INSTALL_DIR}/include
    ${EOSIO_INSTALL_DIR}/include/libc++/upstream/include
    ${EOSIO_INSTALL_DIR}/include/musl/upstream/include
    ${BOOST_INCLUDE_DIR}
)


#file(GLOB_RECURSE RESOURCE_FILES  ${CMAKE_CURRENT_SOURCE_DIR} *.c *.h *.cpp *.hpp )
#list(APPEND RESOURCE_FILES db/DB_battleai.h)
file(GLOB RESOURCE_FILES
        interface.cpp
        db/*.h
        util/*.h util/*.cpp
        user/*.h user/*.cpp
        game/*.h game/*.cpp
        )

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
set(CMAKE_CXX_COMPILER
        ${WASM_INSTALL_DIR}/bin/clang)
set(CMAKE_CXX_CREATE_SHARED_LIBRARY
        "${WASM_INSTALL_DIR}/bin/llvm-link -only-needed -o <TARGET> <OBJECTS>")

add_library(templet SHARED
        ${RESOURCE_FILES})

target_link_libraries(templet
        ${EOSIO_CONTRACTSDK_PATH}/lib/libc.bc
        ${EOSIO_CONTRACTSDK_PATH}/lib/libc++.bc
        ${EOSIO_CONTRACTSDK_PATH}/lib/eosiolib.bc)

set(CONTRACT_ASSEMBLY_FILE ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}.s)
set(CONTRACT_WAST_FILE_T ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}_t.wast)
set(CONTRACT_WAST_FILE ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}.wast)
set(CONTRACT_ABI_FILE ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}.abi)

add_custom_target(assembly ALL
        DEPENDS templet)
add_custom_command(
        TARGET assembly
#        OUTPUT ${CONTRACT_ASSEMBLY_FILE}
        COMMAND ${WASM_INSTALL_DIR}/bin/llc
        -thread-model=single
        --asm-verbose=false
        -o ${CONTRACT_ASSEMBLY_FILE} $<TARGET_FILE:templet>
        DEPENDS $<TARGET_FILE:templet>)


add_custom_target(wast ALL
        DEPENDS assembly)
add_custom_command(
        TARGET wast
#        OUTPUT ${CONTRACT_WAST_FILE_T}
        COMMAND ${S2WASM_PATH}
        -o ${CONTRACT_WAST_FILE_T}
        -s 16384
        ${CONTRACT_ASSEMBLY_FILE}
        DEPENDS ${CONTRACT_ASSEMBLY_FILE})


add_custom_target(wast2 ALL
        DEPENDS wast)
add_custom_command(
        TARGET wast2
#        OUTPUT ${CONTRACT_WAST_FILE}
        COMMAND ${WASTS2WASM_PATH}
        ${CONTRACT_WAST_FILE_T}
        ${CONTRACT_WAST_FILE}
        -n
        DEPENDS ${CONTRACT_WAST_FILE_T})

add_custom_target(abi ALL)
add_custom_command(
        TARGET abi
        COMMAND ${ABIGEN} -extra-arg=-c
        -extra-arg=--std=c++14
        -extra-arg=--target=wasm32
        -extra-arg=-nostdinc
        -extra-arg=-nostdinc++
        -extra-arg=-DABIGEN
        -extra-arg=-I${EOSIO_INSTALL_DIR}/include/libc++/upstream/include
        -extra-arg=-I${EOSIO_INSTALL_DIR}/include/musl/upstream/include
        -extra-arg=-I${BOOST_INCLUDE_DIR}
        -extra-arg=-I${EOSIO_INSTALL_DIR}/include
        -extra-arg=-I${CMAKE_CURRENT_SOURCE_DIR}
        -extra-arg=-fparse-all-comments -destination-file=${CONTRACT_ABI_FILE} -verbose=0
        -context=${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/interface.cpp --
)
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(DEFAULT_BUILD_TYPE "Release")
project(
    NosoHive 
    VERSION 1.0.0 
    DESCRIPTION "NosoHive"
    HOMEPAGE_URL "https://github.com/NosoLab/NosoHive"
)
include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                         GIT_TAG 3020c34ae2b732121f37433e61599c34535e68a8) 
                         FetchContent_MakeAvailable(cpr)


# Add the common directory to the include directories
include_directories(common)
include_directories(libs/ini)

find_package(nlohmann_json 3.11.2 REQUIRED)

# Create the CommonLib library
add_library(NosoCore
    common/common_file.cpp
)


# Add the executable targets
add_executable(wallet wallet/wallet.cpp)
add_executable(rpc rpc/rpc.cpp)
add_executable(tester-rpc tester-rpc/tester-rpc.cpp)

# Link the common library to the executables
target_link_libraries(wallet NosoCore)
target_link_libraries(rpc NosoCore)
target_link_libraries(tester-rpc PRIVATE NosoCore cpr::cpr nlohmann_json::nlohmann_json)

# Set the output path for the executables
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

# Create a custom target to copy files to the NosoHive directory
add_custom_target(copy_target ALL
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/NosoHive
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/NosoHive/data
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/NosoHive/libs
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:wallet> ${CMAKE_BINARY_DIR}/NosoHive
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:rpc> ${CMAKE_BINARY_DIR}/NosoHive
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:tester-rpc> ${CMAKE_BINARY_DIR}/NosoHive
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/README.md ${CMAKE_BINARY_DIR}/NosoHive
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.txt ${CMAKE_BINARY_DIR}/NosoHive
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/res/config.ini.example ${CMAKE_BINARY_DIR}/NosoHive
    DEPENDS wallet rpc tester-rpc
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/bin
)

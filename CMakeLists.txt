cmake_minimum_required(VERSION 3.10)

project(NosoHive VERSION 1.0.0 DESCRIPTION "NosoHive Project")

# Додаємо директиву для включення файлів із common
include_directories(common)

# Створюємо бібліотеку common, яка включає файли з common
add_library(CommonLib
    common/common_file.cpp
)

# Додаємо виконувані файли для кожного проекту
add_executable(wallet wallet/wallet.cpp)
add_executable(rpc rpc/rpc.cpp)
add_executable(tester-rpc tester-rpc/tester-rpc.cpp)

# Лінкуємо common бібліотеку до кожного проекту
target_link_libraries(wallet CommonLib)
target_link_libraries(rpc CommonLib)
target_link_libraries(tester-rpc CommonLib)

# Визначаємо шлях до папки для виходу виконуваних файлів
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

# Копіюємо виконувані файли в окрему папку
add_custom_target(copy_target ALL
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/NosoHive
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:wallet> ${CMAKE_BINARY_DIR}/NosoHive
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:rpc> ${CMAKE_BINARY_DIR}/NosoHive
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:tester-rpc> ${CMAKE_BINARY_DIR}/NosoHive
    DEPENDS wallet rpc tester-rpc
)

cmake_minimum_required(VERSION 3.28)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/external/vcpkg/scripts/buildsystems/vcpkg.cmake)

project(test)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)

find_path(TCLAP_INCLUDE_DIRS "tclap/Arg.h")

add_executable(
  ${PROJECT_NAME}
  src/main.cxx
  src/cmd_line_params.cxx
  src/modules/checksum_module.cxx
  src/modules/words_module.cxx
  src/modules/module_executor.cxx
  src/algorithm/word_count.cxx
)

target_include_directories(${PROJECT_NAME} PRIVATE src/include)

target_include_directories(
  ${PROJECT_NAME} PRIVATE ${TCLAP_INCLUDE_DIRS}
)

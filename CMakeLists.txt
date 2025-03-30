cmake_minimum_required(VERSION 3.20)
project(luahook VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ============================================================

## Find dependencies
find_package(lua REQUIRED)

file(GLOB SRC_FILES "src/*.cpp")
## Create main executable
add_executable(luahook ${SRC_FILES})
target_include_directories(luahook
  PRIVATE 
    "${CMAKE_CURRENT_LIST_DIR}/source"
)
target_link_libraries(
  luahook
  PRIVATE
  lua
)

# ============================================================


target_include_directories(luahook PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

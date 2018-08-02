# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.5)

set( CMAKE_MODULE_PATH
    ${CMAKE_MODULE_PATH}
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules)

# set output dirs
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/bin)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
set(CMAKE_CXX_STANDARD 14) # C++14

set(SOURCES
main.cpp
utils.cpp
test.cpp
maths.cpp
)

set(HEADERS
utils.hpp
maths.hpp
)

add_definitions(-DVERSION="${VERSION_STRING}")

find_package(SDL2 REQUIRED)






# Set the project name
project (guitar2midi)


# Add an executable
add_executable(guitar2midi ${SOURCES} ${HEADERS})
target_link_libraries(guitar2midi ${SDL2_LIBRARIES} fftw3)


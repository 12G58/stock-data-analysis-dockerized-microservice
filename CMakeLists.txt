cmake_minimum_required(VERSION 3.10)

# Project name and version
project(data-analytics-microservice VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the source files with correct paths
set(SOURCES
    src/main.cpp
    src/data_fetcher.cpp
    src/data_processor.cpp
)

# Include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/external/Crow/include 
    /usr/include/websocketpp
    /usr/include/jsoncpp
)

# Use pkg-config to find libcurl
find_package(PkgConfig REQUIRED)
pkg_check_modules(CURL REQUIRED libcurl)

# Find OpenSSL
find_package(OpenSSL REQUIRED)

# Use pkg-config to find jsoncpp
pkg_check_modules(JSONCPP REQUIRED jsoncpp)

# Include curl directories
include_directories(${CURL_INCLUDE_DIRS})

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link with OpenSSL, libcurl, jsoncpp, and Threads
target_link_libraries(${PROJECT_NAME} PRIVATE OpenSSL::SSL OpenSSL::Crypto ${CURL_LIBRARIES} ${JSONCPP_LIBRARIES})

# Enable multi-threading support
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)

# Add compile definitions
target_compile_definitions(${PROJECT_NAME} PRIVATE _GLIBCXX_USE_CXX11_ABI=1)
target_compile_definitions(${PROJECT_NAME} PRIVATE CROW_ENABLE_SSL)

# Define compiler options
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

# Installation rules (optional)
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(FILES ${CMAKE_SOURCE_DIR}/include/data_fetcher.h DESTINATION include)
install(FILES ${CMAKE_SOURCE_DIR}/include/data_processor.h DESTINATION include)

# Print summary
message(STATUS "CMake build configuration complete!")
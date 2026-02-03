cmake_minimum_required(VERSION 3.16)

project(FeedforwardNeuralNetwork VERSION 0.1.0 LANGUAGES CXX)

option(FNN_BUILD_SHARED "Build FNN as a shared library" OFF)
option(FNN_ENABLE_WARNINGS "Enable extra compiler warnings" ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Helps editor tooling (clangd) find include paths and flags.
# Safe to keep on for a small learning repo.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(FNN_PUBLIC_HEADERS
    include/fnn/config.hpp
    include/fnn/fnn.hpp
    include/fnn/activation_func.hpp
    include/fnn/layer.hpp
    include/fnn/loss_func.hpp
    include/fnn/model.hpp
    include/fnn/tensor2D.hpp
)

set(FNN_SOURCES
    src/activation_func.cpp
    src/layer.cpp
    src/loss_func.cpp
    src/model.cpp
    src/tensor2D.cpp
)

if(FNN_BUILD_SHARED)
    add_library(${PROJECT_NAME} SHARED ${FNN_SOURCES} ${FNN_PUBLIC_HEADERS})
else()
    add_library(${PROJECT_NAME} STATIC ${FNN_SOURCES} ${FNN_PUBLIC_HEADERS})
endif()

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)

if(FNN_ENABLE_WARNINGS)
    if(MSVC)
        target_compile_options(${PROJECT_NAME} PRIVATE /W4 /permissive-)
    else()
        target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
    endif()
endif()

# Install library + headers
install(TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}Targets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

install(EXPORT ${PROJECT_NAME}Targets
    FILE ${PROJECT_NAME}Targets.cmake
    NAMESPACE ${PROJECT_NAME}::
    DESTINATION lib/cmake/${PROJECT_NAME}
)

install(DIRECTORY include/ DESTINATION include)

cmake_minimum_required(VERSION 3.0)
project(Looker)

option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
add_subdirectory(api/glfw)

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /O2 /openmp")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -Wextra -Wpedantic -std=c++11 -fopenmp")
endif()

include_directories(src/utility/
                    api/glfw/include/
                    api/glm/
                    api/stb/
                    api/imgui/
                    api/tinyobjloader/
                    ${VULKAN_INCLUDE_DIR})

file(GLOB API_SOURCES api/imgui/.cpp)

file(GLOB PROJECT_HEADERS src/utility/*.h)

file(GLOB PROJECT_SOURCES src/*.cpp
                          src/utility/*.cpp)

file(GLOB PROJECT_SHADERS res/shaders/*.glsl
                          res/shaders/*.frag
                          res/shaders/*.vert)

file(GLOB PROJECT_CONFIGS CMakeLists.txt
                          README.md
                         .gitattributes
                         .gitignore
                         .gitmodules)

source_group("Headers" FILES ${PROJECT_HEADERS})
source_group("Shaders" FILES ${PROJECT_SHADERS})
source_group("Sources" FILES ${PROJECT_SOURCES})
source_group("API" FILES ${API_SOURCES})


set(VULKAN_INCLUDE_DIR "$ENV{VULKAN_SDK}/include")
set(VULKAN_LIBRARY "$ENV{VULKAN_SDK}/lib/libvulkan.so")

add_definitions(-DGLFW_INCLUDE_NONE
                -DPROJECT_SOURCE_DIR=\"${PROJECT_SOURCE_DIR}\")

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS}
                               ${PROJECT_SHADERS} ${PROJECT_CONFIGS}
                               ${API_SOURCES})

target_link_libraries(${PROJECT_NAME} glfw ${GLFW_LIBRARIES}
                    ${VULKAN_LIBRARY})

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME})

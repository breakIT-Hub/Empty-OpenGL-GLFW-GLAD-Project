cmake_minimum_required(VERSION 3.1)

project(DemoProject)

# GCC settings
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -g")
# source files
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs")
set(INC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")

include_directories(${SRC_DIR} ${INC_DIR})
file(GLOB SRC_FILES "${SRC_DIR}/*.cpp" "${INC_DIR}/*.h")

# executable definition and properties
add_executable(${PROJECT_NAME} ${SRC_FILES})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)
target_include_directories(${PROJECT_NAME} PRIVATE "${INC_DIR}" "${SRC_DIR}")
#add_subdirectory(${SRC_DIR})
#GLFW
# disable some glfw builds. e.g. examples
set(GLFW_DIR "${LIB_DIR}/glfw")
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")
add_subdirectory("${GLFW_DIR}")
target_link_libraries(${PROJECT_NAME} "glfw" "${GLFW_LIBRARIES}")
target_include_directories(${PROJECT_NAME} PRIVATE "${GLFW_DIR}/include")
####

# GLAD
set(GLAD_DIR "${LIB_DIR}/glad")
add_subdirectory("${GLAD_DIR}")
#add_library("glad" "${GLAD_DIR}/src/glad.c")
#target_include_directories("glad" PRIVATE "${GLAD_DIR}/include")
target_link_libraries(${PROJECT_NAME} "glad" "${GLAD_LIBRARIES}")
target_include_directories(${PROJECT_NAME} PRIVATE "${GLAD_DIR}/include")
#find_package(PkgConfig REQUIRED)
#pkg_search_module(GLFW REQUIRED glfw3)
#include_directories(${GLFW_INCLUDE_DIRS} )
#target_link_libraries(${PROJECT_NAME} GL ${GLFW_LIBRARIES})
#target_link_libraries(${PROJECT_NAME} ${GLFW_STATIC_LIBRARIES})

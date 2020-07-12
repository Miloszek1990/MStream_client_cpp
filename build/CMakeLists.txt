cmake_minimum_required(VERSION 3.13.4)
set(CMAKE_CXX_STANDARD 17)

set( CMAKE_BUILD_TYPE Debug )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17" )

project(MStream)

set(raspicam_DIR "/usr/local/lib/cmake/") # /usr/local/lib/cmake/raspicamConfig.cmake

find_package( OpenCV REQUIRED )
find_package( raspicam REQUIRED )

message(${OpenCV_INCLUDE_DIRS})

message(${raspicam_DIR})

include_directories(
                    ../include/
                    ${OpenCV_INCLUDE_DIRS}
                    ${raspicam_DIR}
                   )

add_executable(
    ${PROJECT_NAME}
    ../main.cpp
    ../source/Client.cpp
)

target_link_libraries( ${PROJECT_NAME} 
                       ${OpenCV_LIBS}
                       ${raspicam_LIBS}
                       ${raspicam_CV_LIBS} )
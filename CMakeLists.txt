cmake_minimum_required(VERSION 3.23)
project(LearnJNI)

set(CMAKE_C_STANDARD 11)

set(JAVA_HOME /Users/pokeum/Library/Java/JavaVirtualMachines/openjdk-18/Contents/Home)

include_directories(${JAVA_HOME}/include)
include_directories(${JAVA_HOME}/include/darwin)

add_executable(LearnJNI
        TheJavaNativeInterface/chapter02/HelloWorld.c
        TheJavaNativeInterface/chapter02/HelloWorld.h
        TheJavaNativeInterface/chapter03/Prompt/Prompt.c
        TheJavaNativeInterface/chapter03/Prompt/Prompt.h)

cmake_minimum_required(VERSION 3.15)
project(Project)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -Wl,-Bstatic -lstdc++ -lpthread -Wl,-Bdynamic")


add_executable(Project Time.h Staff.cpp Staff.h Time.cpp  Person.h LinkedList.cpp LinkedList.h Person.cpp File.cpp File.h main.cpp)
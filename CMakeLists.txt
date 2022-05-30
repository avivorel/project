cmake_minimum_required(VERSION 3.16)
project(project)

set(CMAKE_CXX_STANDARD 14)

add_executable(project main.cpp EmployeeManager.cpp EmployeeManager.h Company.cpp Company.h HashTable.h DList.h RankAVL.h)

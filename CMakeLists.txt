cmake_minimum_required(VERSION 3.16)
project(project)

set(CMAKE_CXX_STANDARD 14)

add_executable(project main.cpp EmployeeManager.cpp EmployeeManager.h Company.cpp HashTable.h DList.h RankAVL.h Employee.cpp Employee.h exceptions.h Essentials.h AVLTree.h UnionFind.h Array.h debugFunctions.h)

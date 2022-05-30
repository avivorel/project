//
// Created by Aviv on 5/30/2022.
//

#ifndef PROJECT_EXCEPTIONS_H
#define PROJECT_EXCEPTIONS_H

#include <exception>

class ALLOCATION_ERROR public std::exception{};
class INVALID_INPUT public std::exception{};
class SUCCESS public std::exception{};
class FAILURE public std::exception{};

#endif //PROJECT_EXCEPTIONS_H

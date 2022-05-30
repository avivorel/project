//
// Created by Aviv on 5/30/2022.
//

#ifndef PROJECT_COMPANY_H
#define PROJECT_COMPANY_H

#include "RankAVL.h"
#include "Employee.h"
#include "DList.h"
#include "HashTable.h"

class Company {
private:
    RankAVL<int,Employee*> employees_by_salary;
    RankAVL<int,Employee*> employees_by_id;


public:

};


#endif //PROJECT_COMPANY_H

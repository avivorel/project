//
// Created by Aviv on 5/30/2022.
//

#ifndef PROJECT_EMPLOYEEMANAGER_H
#define PROJECT_EMPLOYEEMANAGER_H

#include "HashTable.h"
#include "DList.h"
#include "RankAVL.h"
#include "Employee.h"
#include "Essentials.h"

class EmployeeManager {
private:
    RankAVL<employeeCondition_Id,Employee*> all_employees;
    RankAVL<employeeCondition_Salary_Id,Employee*> all_employees_by_salary;
    HashTable<int,Employee*> all_employees_hash;
public:
    void update();
};


#endif //PROJECT_EMPLOYEEMANAGER_H

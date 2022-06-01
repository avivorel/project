//
// Created by Aviv on 5/30/2022.
//

#ifndef PROJECT_COMPANY_H
#define PROJECT_COMPANY_H

#include "RankAVL.h"
#include "Employee.h"
#include "DList.h"
#include "HashTable.h"
#include "Essentials.h"

class Company {
private:
    RankAVL<employeeCondition_Id,Employee*> employees_by_salary;
    RankAVL<employeeCondition_Salary_Id,Employee*> employees_by_id;
    HashTable<int, Employee*> employees_hash;
public:
    int getId()const;

    int getValue()const;

    int getNumOfEmployees()const;

    void update();

};


#endif //PROJECT_COMPANY_H

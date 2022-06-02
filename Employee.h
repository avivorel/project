//
// Created by Aviv on 5/30/2022.
//

#ifndef PROJECT_EMPLOYEE_H
#define PROJECT_EMPLOYEE_H

#include "Essentials.h"
#include "AVLTree.h"
#include "HashTable.h"

class Employee {
    int id;
    int grade;
    int company_id;
    int salary;
public:
    int getId() const;
    int getCompanyId() const;
    int getGrade() const;
    int getSalary() const;
};


class Company {
private:
    AVLTree<employeeCondition_Id,Employee*> employees_by_salary;
    AVLTree<employeeCondition_Salary_Id,Employee*> employees_by_id;
    HashTable<int, Employee*> employees_hash;
public:
    int getId()const;

    int getValue()const;

    int getNumOfEmployees()const;

    void update();

};


#endif //PROJECT_EMPLOYEE_H

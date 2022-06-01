//
// Created by Aviv on 5/30/2022.
//

#ifndef PROJECT_EMPLOYEE_H
#define PROJECT_EMPLOYEE_H


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


#endif //PROJECT_EMPLOYEE_H

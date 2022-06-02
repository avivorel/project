//
// Created by Aviv on 6/1/2022.
//

#ifndef PROJECT_ESSENTIALS_H
#define PROJECT_ESSENTIALS_H

class Company;
class Employee;

class companyCondition_Id {
public:
    Company operator()(Company &first, Company &second) const {
        if (first.getId() > second.getId())
            return first;
        else {
            return second;
        }
    }
};


// How it works? First, it judges by the biggest salary, in case they're the same, by ID.
class employeeCondition_Salary_Id{
public:
    Employee& operator()(Employee& employee_one, Employee& employee_second) const{
        if(employee_one.getSalary() > employee_second.getSalary()){
            return employee_one;
        }
        else if(employee_one.getSalary() == employee_second.getSalary()){
            if(employee_one.getId() > employee_second.getId()){
                return employee_one;
            }
            else{
                return employee_second;
            }
        }
        return employee_second;
    }
};

class employeeCondition_Id{
    Employee& operator()(Employee& first_employee, Employee& second_employee){
        if(first_employee.getId()> second_employee.getId()){
            return first_employee;
        }
        return second_employee;
    }
};

#endif //PROJECT_ESSENTIALS_H

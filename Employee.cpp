//
// Created by Aviv on 5/30/2022.
//

#include "Employee.h"

int Employee::getId() const {
    return this->id;
}

int Employee::getCompanyId() const {
    return this->company_id;
}

int Employee::getGrade() const {
    return this->grade;
}

int Employee::getSalary() const{
    return this->salary;
}

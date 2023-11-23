// Created by Jianfeng Lin

#include "Patient.h"
#include <iostream>

Patient::Patient(const std::string& _name, int _age)
    : name(_name), age(_age) {}

Patient::~Patient() {}

void Patient::setName(const std::string& _name) {
    name = _name;
}

std::string Patient::getName() const {
    return name;
}

void Patient::setAge(int _age) {
    age = _age;
}

int Patient::getAge() const {
    return age;
}

void Patient::displayInfo() const {
    std::cout << "Name: " << name << "\n";
    std::cout << "Age: " << age << "\n";
}

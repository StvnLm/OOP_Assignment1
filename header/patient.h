// Created by Jianfeng Lin

#pragma once
#include <string>

class Patient {
private:
    std::string name;
    int age;

public:
    Patient(const std::string& _name, int _age);
    virtual ~Patient();

    void setName(const std::string& _name);
    std::string getName() const;

    void setAge(int _age);
    int getAge() const;

    // Virtual function to display patient information
    virtual void displayInfo() const;
};

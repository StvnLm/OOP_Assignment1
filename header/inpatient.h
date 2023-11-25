// Created by Jianfeng Lin

#pragma once
#include "Patient.h"

class Inpatient : public Patient {
private:
    int roomNumber;

public:
    Inpatient(const std::string& _name, int _age, int _roomNumber);
    ~Inpatient();

    void setRoomNumber(int _roomNumber);
    int getRoomNumber() const;

    // Override the displayInfo function
    void displayInfo() const override;

};

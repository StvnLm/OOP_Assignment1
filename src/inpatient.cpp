// Created by Jianfeng Lin

#include "../header/Inpatient.h"
#include <iostream>

Inpatient::Inpatient(const std::string& _name, int _age, int _roomNumber)
    : Patient(_name, _age), roomNumber(_roomNumber) {}

Inpatient::~Inpatient() {}

void Inpatient::setRoomNumber(int _roomNumber) {
    roomNumber = _roomNumber;
}

int Inpatient::getRoomNumber() const {
    return roomNumber;
}

void Inpatient::displayInfo() const {
    Patient::displayInfo();
    std::cout << "Room Number: " << roomNumber << "\n";
}
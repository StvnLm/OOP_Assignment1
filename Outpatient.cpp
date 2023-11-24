// Created by Jianfeng Lin

#include "Outpatient.h"
#include <iostream>

Outpatient::Outpatient(const std::string& _name, int _age, const std::string& _appointmentDate)
    : Patient(_name, _age), appointmentDate(_appointmentDate) {}

Outpatient::~Outpatient() {}

void Outpatient::setAppointmentDate(const std::string& _appointmentDate) {
    appointmentDate = _appointmentDate;
}

std::string Outpatient::getAppointmentDate() const {
    return appointmentDate;
}

void Outpatient::displayInfo() const {
    Patient::displayInfo();
    std::cout << "Appointment Date: " << appointmentDate << "\n";
}

// Created by Jianfeng Lin

#pragma once
#include "Patient.h"
#include <string>

class Outpatient : public Patient {
private:
    std::string appointmentDate;

public:
    Outpatient(const std::string& _name, int _age, const std::string& _appointmentDate);
    ~Outpatient();

    void setAppointmentDate(const std::string& _appointmentDate);
    std::string getAppointmentDate() const;

    // Override the displayInfo function
    void displayInfo() const override;
};

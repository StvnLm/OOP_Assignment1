#ifndef MED_STAFF_H
#define MED_STAFF_H

#include <iostream>
#include <string>
#include <vector>
#include <array>

class MedicalStaff {
protected:
    std::string name;
    std::string specialty;
    using ScheduleType = std::array<int, 3>; // Day, Hour, Minute
    std::vector<ScheduleType> schedule;

public:
    MedicalStaff(const std::string& n, const std::string& s) : name(n), specialty(s) {}

    std::string getName() const;
    std::string getSpecialty() const;

    void displaySchedule() const;
    bool isAvailable(int day, int hour, int minute); // Declaration for isAvailable
    void addAppointment(int day, int hour, int minute); // Declaration for addAppointment
};

class Doctor : public MedicalStaff {
public:
    Doctor(const std::string& name, const std::string& specialty) : MedicalStaff(name, specialty) {}
};

class Nurse : public MedicalStaff {
public:
    Nurse(const std::string& name, const std::string& specialty) : MedicalStaff(name, specialty) {}
};

#endif

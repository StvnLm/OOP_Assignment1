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

    bool isAvailable(int day, int hour, int minute) const {
        for (const auto& timeSlot : schedule) {
            if (timeSlot[0] == day && timeSlot[1] == hour && timeSlot[2] == minute) {
                return false; // Appointment slot already taken
            }
        }
        return true;
    }

    void addAppointment(int day, int hour, int minute) {
        if (!isAvailable(day, hour, minute)) {
            throw std::runtime_error("Time slot not available");
        }
        schedule.push_back({day, hour, minute});
    }

    std::string getName() const {
        return name;
    }

    std::string getSpecialty() const {
        return specialty;
    }

    void displaySchedule() const {
        for (const auto& timeSlot : schedule) {
            std::cout << "\nOn day " << timeSlot[0] << " at " << timeSlot[1] << ":" << timeSlot[2];
        }
    }
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
#include "../header/med_staff.h"  

// Constructor
MedicalStaff::MedicalStaff(const std::string& n, const std::string& s) : name(n), specialty(s) {}

// Check if the medical staff is available at a given time
bool MedicalStaff::isAvailable(int day, int hour, int minute) const {
    for (const auto& timeSlot : schedule) {
        if (timeSlot[0] == day && timeSlot[1] == hour && timeSlot[2] == minute) {
            return false; // Time slot already taken
        }
    }
    return true;
}

// Add an appointment to the medical staff's schedule
void MedicalStaff::addAppointment(int day, int hour, int minute) {
    if (!isAvailable(day, hour, minute)) {
        throw std::runtime_error("Time slot not available");
    }
    schedule.push_back({day, hour, minute});
}

// Get the name of the medical staff
std::string MedicalStaff::getName() const {
    return name;
}

// Get the specialty of the medical staff
std::string MedicalStaff::getSpecialty() const {
    return specialty;
}

// Display the medical staff's schedule
void MedicalStaff::displaySchedule() const {
    for (const auto& timeSlot : schedule) {
        std::cout << "\nOn day " << timeSlot[0] << " at " << timeSlot[1] << ":" << timeSlot[2];
    }
}

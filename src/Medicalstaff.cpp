#include "../header/med_staff.h"

std::string MedicalStaff::getName() const {
    return name;
}

std::string MedicalStaff::getSpecialty() const {
    return specialty;
}

void MedicalStaff::displaySchedule() const {
    for (const auto& timeSlot : schedule) {
        std::cout << "\nOn day " << timeSlot[0] << " at " << timeSlot[1] << ":" << timeSlot[2];
    }
}

bool MedicalStaff::isAvailable(int day, int hour, int minute) {
   std::array<int, 3> requestedTimeSlot = {day, hour, minute};

    for (const auto& timeSlot : schedule) {
        if (timeSlot[0] == day && timeSlot[1] == hour && timeSlot[2] == minute) {
           
            return false;
        }
    }

   
    return true;
}

void MedicalStaff::addAppointment(int day, int hour, int minute) {
    if (!isAvailable(day, hour, minute)) {
        throw std::runtime_error("Time slot not available");
    }
    schedule.push_back({day, hour, minute});
}
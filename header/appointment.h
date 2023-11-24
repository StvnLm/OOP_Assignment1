#ifndef APPOINTMENT_H
#define APPOINTMENT_H
#include "./patient.h"
#include "./inpatient.h"
#include "./med_staff.h"
#include <string>
#include <memory>  
#include <vector>

class Appointment {
public:
    Appointment();
    void addAppointment(int day, int month, int year, int hour, int min, Patient& patient, MedicalStaff& staff);
    void removeAppointment(int day, int month, int year, int hour, int min, Patient& patient, MedicalStaff& staff);
    void printAppointments() const;

// New methods to get appointment details
    std::string getPatientName(int index) const {
        if (index >= 0 && index < appointments.size()) {
            return appointments[index]->patient->getName();
        }
        return "";
    }

    std::string getStaffName(int index) const {
        if (index >= 0 && index < appointments.size()) {
            return appointments[index]->medicalStaff->getName();
        }
        return "";
    }

    std::string getDate(int index) const {
        if (index >= 0 && index < appointments.size()) {
            return std::to_string(appointments[index]->day) + "/" +
                   std::to_string(appointments[index]->month) + "/" +
                   std::to_string(appointments[index]->year);
        }
        return "";
    }

    std::string getTime(int index) const {
        if (index >= 0 && index < appointments.size()) {
            return std::to_string(appointments[index]->hour) + ":" +
                   std::to_string(appointments[index]->min);
        }
        return "";
    }

    int getNumberOfAppointments() const {
        return appointments.size();
    }


private:
    struct AppointmentDetails {
        int day, month, year, hour, min;
        Patient* patient;
        MedicalStaff* medicalStaff;
    };

    std::vector<std::unique_ptr<AppointmentDetails>> appointments;

    bool isValidDate(int day, int month, int year) const;
    bool isValidTime(int hour, int min) const;
};

#endif // APPOINTMENT_H
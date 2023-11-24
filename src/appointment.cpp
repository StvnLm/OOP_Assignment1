#include "../header/Appointment.h"
#include <iostream>

Appointment::Appointment() {}

void Appointment::addAppointment(int day, int month, int year, int hour, int min, Patient& patient, MedicalStaff& staff) {
    if (!isValidDate(day, month, year) || !isValidTime(hour, min)) {
        std::cerr << "Invalid date or time for appointment.\n";
        return;
    }

    auto appt = std::make_unique<AppointmentDetails>();
    appt->day = day;
    appt->month = month;
    appt->year = year;
    appt->hour = hour;
    appt->min = min;
    appt->patient = &patient;
    appt->medicalStaff = &staff;

    appointments.push_back(std::move(appt));
}

void Appointment::removeAppointment(int day, int month, int year, int hour, int min, Patient& patient, MedicalStaff& staff) {
    appointments.erase(std::remove_if(appointments.begin(), appointments.end(),
        [&](const std::unique_ptr<AppointmentDetails>& appt) {
            return appt->day == day && appt->month == month && appt->year == year &&
                   appt->hour == hour && appt->min == min &&
                   appt->patient == &patient && appt->medicalStaff == &staff;
        }), appointments.end());
}

void Appointment::printAppointments() const {
    for (const auto& appt : appointments) {
        std::cout << "Appointment on " << appt->day << "/" << appt->month << "/" << appt->year
                  << " at " << appt->hour << ":" << appt->min
                  << " with " << appt->patient->get_name()
                  << " and " << appt->medicalStaff->getName() << std::endl;
    }
}

bool Appointment::isLeapYear(int year) const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool Appointment::isValidDate(int day, int month, int year) const {
    if (year < 1900 || year > 2100) return false; // Example year range
    if (month < 1 || month > 12) return false;

    const int monthLengths[12] = {31, (isLeapYear(year) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return day > 0 && day <= monthLengths[month - 1];
}

bool Appointment::isValidTime(int hour, int min) const {
    return (hour >= 0 && hour < 24) && (min >= 0 && min < 60);
}

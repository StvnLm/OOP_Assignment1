#ifndef APPOINTMENT_H
#define APPOINTMENT_H
#include "./patient.h"
#include "./inpatient.h"
#include "./med_staff.h"
#include <string>

class Appointment {
  public:
    Appointment();
    int calculateIndex(int day, int month, int year);
    void addAppointment(int day, int month, int year, int hour, int min, Patient& patient, MedicalStaff& staff);
    void removeAppointment(int day, int month, int year, int hour, int min, Patient& patient, MedicalStaff& staff);
    void printAppointments();
  private:
    static const int appointmentTableSize = 365;
    struct appointment {
      int month;
      int day;
      int year;
      int hour;
      int min;
      Patient* patient;
      MedicalStaff* medicalStaff;
      appointment* next;      
    };
    appointment* appointmentTable[appointmentTableSize];
};

#endif

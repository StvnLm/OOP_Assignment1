#ifndef APPOINTMENT_H
#define APPOINTMENT_H
#include "./patient.h"
#include "./inpatient.h"
#include <string>

class Appointment {
  public:
    Appointment();
    int calculateIndex(int day, int month, int year);
    void addAppointment(int day, int month, int year, int hour, int min, Patient& patient);
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
      appointment* next;      
    };
    appointment* appointmentTable[appointmentTableSize];
};

#endif

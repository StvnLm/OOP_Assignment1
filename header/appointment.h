#ifndef APPOINTMENT_H
#define APPOINTMENT_H
#include "./patient.h"
#include "./inpatient.h"
#include <string>

class Appointment {
  public:
    Appointment();
    void addAppointment(int day, int hour, int min, Patient& patient);
    void printAppointments();
  private:
    static const int appointmentTableSize = 365;
    struct appointment {
      int hour;
      int min;
      Patient* patient;
      appointment* next;      
    };
    appointment* appointmentTable[appointmentTableSize];
};

#endif

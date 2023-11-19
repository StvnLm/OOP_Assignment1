#ifndef APPOINTMENT_H
#define APPOINTMENT_H
#include <string>

class Appointment {
  public:
    Appointment();
    addAppointment(int year, int month, int day, string patientName, string staffName);
  private:
    static const int appointmentTableSize = 365;
    struct appointment {
      int year;
      int month;
      int day;
      string patientName;
      string staffName;
      appointment* next;      
    }
    appointment* appointmentTable[appointmentTableSize];
}

#endif

#include "../header/appointment.h"
#include "../header/patient.h"
#include <iostream>
#include <exception>
#include <string>

Appointment::Appointment(){
  for (int i = 0; i < appointmentTableSize; i++){
    appointmentTable[i] = new appointment;
    appointmentTable[i]->hour = 0;
    appointmentTable[i]->min = 0;
    appointmentTable[i]->patient = nullptr;
    appointmentTable[i]->next = nullptr;
  }
}

void Appointment::addAppointment(int day, int hour, int min, Patient& patient){
  if (appointmentTable[day]->patient == nullptr){ //base case if index is empty
    appointmentTable[day]->hour = hour;
    appointmentTable[day]->min = min;
    appointmentTable[day]->patient = &patient;
  }
  else {
    appointment* apptPtr = appointmentTable[day];
    appointment* newPtr = new appointment;
    newPtr->hour = hour;
    newPtr->min = min;
    newPtr->patient = &patient;
    newPtr->next = nullptr;
    while (apptPtr->next != nullptr)
    {
      apptPtr = apptPtr->next;
    }
    apptPtr->next = newPtr;
  }
}

void Appointment::printAppointments(){
  appointment* ptr;
  for (int i = 0; i < appointmentTableSize; i++){
    ptr = appointmentTable[i];
    while (ptr != nullptr && ptr->patient != nullptr){
      std::cout << " ----------------------------- " << std::endl;
      std::cout << "Day " << i << std::endl;
      std::cout << "Patient name: " << ptr->patient->get_name() << std::endl;
      std::cout << "Appointment time: " << ptr->hour << ":" << ptr->min << std::endl;
      ptr = ptr->next;
    }
  }
}

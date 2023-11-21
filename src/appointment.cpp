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

int Appointment::calculateIndex(int day, int month, int year){
  int index = 0;
  int feb = 28;

  // Check if leap year
  if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
    feb = 29;
  }

  const int monthLengths[12] = {31, feb, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  for (int i = 0; i < month - 1; i++) {
    index += monthLengths[i];
  }
  index += day;
  return index;
};

void Appointment::addAppointment(int day, int month, int year, int hour, int min, Patient& patient){
  int index = calculateIndex(day, month, year);
  if (appointmentTable[index]->patient == nullptr){ //base case if index is empty
    appointmentTable[index]->month = month;
    appointmentTable[index]->day = day;
    appointmentTable[index]->year = year;
    appointmentTable[index]->hour = hour;
    appointmentTable[index]->min = min;
    appointmentTable[index]->patient = &patient;
  }
  else {
    appointment* apptPtr = appointmentTable[index];
    appointment* newPtr = new appointment;
    newPtr->month = month;
    newPtr->day = day;
    newPtr->year = year;
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
      std::cout << "-----------------------------" << std::endl;
      std::cout << "Appointment calendar day " << i << std::endl;
      std::cout << "-----------------------------" << std::endl;
      std::cout << "Appointment day: " << ptr->month << "/" << ptr->day << "/" << ptr->year << std::endl;
      std::cout << "Appointment time: " << ptr->hour << ":" << ptr->min << std::endl;
      std::cout << "Patient name: " << ptr->patient->get_name() << std::endl;
      ptr = ptr->next;
    }
  }
}

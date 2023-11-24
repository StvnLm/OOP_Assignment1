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
    appointmentTable[i]->medicalStaff = nullptr;
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

void Appointment::addAppointment(int day, int month, int year, int hour, int min, Patient& patient, MedicalStaff& staff){
  int index = calculateIndex(day, month, year);
  if (appointmentTable[index]->patient == nullptr){ //base case if index is empty
    appointmentTable[index]->month = month;
    appointmentTable[index]->day = day;
    appointmentTable[index]->year = year;
    appointmentTable[index]->hour = hour;
    appointmentTable[index]->min = min;
    appointmentTable[index]->patient = &patient;
    appointmentTable[index]->medicalStaff = &staff;
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
    newPtr->medicalStaff = &staff;
    newPtr->next = nullptr;
    
    while (apptPtr->next != nullptr)
    {
      apptPtr = apptPtr->next;
    }
    apptPtr->next = newPtr;
  }
}

void Appointment::removeAppointment(int day, int month, int year, int hour, int min, Patient& patient, MedicalStaff& staff){
  appointment* delPtr;
  appointment* ptr1;
  appointment* ptr2;
  string patientName = patient.get_name();
  string staffName = staff.getName();

  int index = calculateIndex(day, month, year);

  // Base case
  if (appointmentTable[index]->patient == nullptr){
    std::cout << "Appointment not found." << std::endl;
  }

  // Case 1 (appointment is first and only value in bucket)
  if (appointmentTable[index]->patient == &patient &&
      appointmentTable[index]->medicalStaff == &staff &&
      appointmentTable[index]->hour == hour &&
      appointmentTable[index]->min == min &&
      appointmentTable[index]->next == nullptr){
      appointmentTable[index]->hour = 0;
      appointmentTable[index]->min = 0;
      appointmentTable[index]->patient = nullptr;
      appointmentTable[index]->medicalStaff = nullptr;
      std::cout << day << "/" << month << "/" << year << " appointment has been deleted for " << patient.get_name() << std::endl;
      }
  else {
    ptr1 = appointmentTable[index]->next;
    ptr2 = appointmentTable[index];

    while (ptr1 != nullptr && 
          ptr1->patient != &patient &&
          ptr1->medicalStaff != &staff &&
          ptr1->hour != hour &&
          ptr1->min != min) {
            ptr2 = ptr1;
            ptr1 = ptr1->next;
          }

    if (ptr1 == nullptr) {
      std::cout << "Patient appointment not found" << std::endl;
    }
    else {
      delPtr = ptr1;
      ptr1 = ptr1->next;
      ptr2->next = ptr1;
      delete delPtr;
      std::cout << day << "/" << month << "/" << year << " appointment has been deleted for " << patient.get_name() << std::endl;
    }
  }
};

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
      std::cout << "Assigned staff member: " << ptr->medicalStaff->getSpecialty() << " " << ptr->medicalStaff->getName() << std::endl;
      ptr = ptr->next;
    }
  }
}

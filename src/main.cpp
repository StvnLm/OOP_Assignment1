// main.cpp
#include "../header/patient.h" // Include the header file
#include "../header/appointment.h" 
#include "../header/inpatient.h"
#include <iostream>
#include <string>
#include <tuple>

using namespace std;

int main() {
    Patient patientSteve("Steven", 12, 'M', "Cold");
    Patient patientBob("Bob", 31, 'M', "Strep throat");
    Patient patientJoanna("Joanna", 75, 'F', "Coronavirus");

	vector<Patient_services> chrisInpatientTreatments;
    Patient_services allergyTreatment;
    allergyTreatment.service_name = "Antihistamines";
    allergyTreatment.dose_schedule = "Twice a day";
    allergyTreatment.start_date = "2023-02-01";
    allergyTreatment.end_date = "2023-02-05";
    chrisInpatientTreatments.push_back(allergyTreatment);
    Patient_services pinkEyeTreatment;
    pinkEyeTreatment.service_name = "Moxeza";
    pinkEyeTreatment.dose_schedule = "Once a day";
    pinkEyeTreatment.start_date = "2023-02-01";
    pinkEyeTreatment.end_date = "2023-02-05";
    chrisInpatientTreatments.push_back(pinkEyeTreatment);

    Patient patientChris("Chris", 24, 'M', "Seasonal allergies");
    Inpatient inpatientChris(patientChris, 13, chrisInpatientTreatments);
   
    Appointment myAppointments;
    myAppointments.addAppointment(12, 1, 30, patientSteve);
    myAppointments.addAppointment(9, 2, 45, patientBob);
    myAppointments.addAppointment(125, 14, 15, patientJoanna);
    myAppointments.addAppointment(256, 16, 55, inpatientChris);
    myAppointments.printAppointments();
    return 0;
}

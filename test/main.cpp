#include <iostream>
#include <vector>
#include <fstream> 
#include <stdexcept>
#include "../header/Inpatient.h"
#include "../header/Outpatient.h"
#include "../header/Appointment.h"
#include "../header/med_staff.h"

// Define your custom exception classes here
class InvalidAgeException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid age entered.";
    }
};

class AppointmentConflictException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Appointment scheduling conflict.";
    }
};

// Define global vectors to store patient records
std::vector<Patient*> patients;
std::vector<MedicalStaff*> med_staff;
std::vector<Appointment*> appointments;

// Function to display the main menu
void displayMainMenu() {
    std::cout << "Hospital Management System\n";
    std::cout << "1. Add Inpatient\n";
    std::cout << "2. Add Outpatient\n";
    std::cout << "3. Schedule Appointment\n";
    std::cout << "4. Manage Medical Staff\n";
    std::cout << "5. Display Patients\n";
    std::cout << "6. Save Data to File\n";
    std::cout << "7. Load Data from File\n";
    std::cout << "8. Exit\n";
    std::cout << "Enter your choice: ";
}

void manageMedicalStaff() {
    std::cout << "1. Add Doctor\n";
    std::cout << "2. Add Nurse\n";
    std::cout << "3. Display Medical Staff\n";
    std::cout << "Enter your choice: ";

    int choice;
    std::cin >> choice;
    std::cin.ignore();

    switch (choice) {
        case 1: {
            std::string name, specialty;
            std::cout << "Enter doctor's name: ";
            getline(std::cin, name);
            std::cout << "Enter doctor's specialty: ";
            getline(std::cin, specialty);

            Doctor* newDoctor = new Doctor(name, specialty);
            med_staff.push_back(newDoctor);
            std::cout << "Doctor added successfully.\n";
            break;
        }
        case 2: {
            std::string name, specialty;
            std::cout << "Enter nurse's name: ";
            getline(std::cin, name);
            std::cout << "Enter nurse's specialty: ";
            getline(std::cin, specialty);

            Nurse* newNurse = new Nurse(name, specialty);
            med_staff.push_back(newNurse);
            std::cout << "Nurse added successfully.\n";
            break;
        }
        case 3: {
            for (const auto& staffMember : med_staff) {
                std::cout << "Name: " << staffMember->getName()
                          << ", Specialty: " << staffMember->getSpecialty() << "\n";
            }
            break;
        }
    }
}

void scheduleAppointment(const std::vector<Patient*>& patients, const std::vector<MedicalStaff*>& med_staff) {
 if (patients.empty() || med_staff.empty()) {
        std::cout << "Patients or Medical Staff not available." << std::endl;
        return; // Use return instead of break
    }

    // Display patients and select a patient
    int patientIndex = -1;
    std::cout << "Select a patient:" << std::endl;
    for (size_t i = 0; i < patients.size(); ++i) {
        std::cout << i + 1 << ". " << patients[i]->getName() << std::endl;
    }
    std::cin >> patientIndex;
    Patient* selectedPatient = patients[patientIndex - 1];

    // Display medical staff and select a staff member
    int staffIndex = -1;
    std::cout << "Select a medical staff member:" << std::endl;
    for (size_t i = 0; i < med_staff.size(); ++i) {
        std::cout << i + 1 << ". " << med_staff[i]->getName() << std::endl;
    }
    std::cin >> staffIndex;
    MedicalStaff* selectedStaff = med_staff[staffIndex - 1];

    // Get appointment date and time
    int day, hour, minute;
    std::cout << "Enter day, hour, and minute for appointment: ";
    std::cin >> day >> hour >> minute;

    // Check availability and schedule appointment
    if (selectedStaff->isAvailable(day, hour, minute)) {
        selectedStaff->addAppointment(day, hour, minute);
        std::cout << "Appointment scheduled successfully." << std::endl;
    } else {
        std::cout << "The selected staff member is not available at this time." << std::endl;
    }
}

void loadDataFromFile() {
    std::ifstream file("hospital_data.txt");
    if (!file.is_open()) {
        std::cerr << "Unable to open file for reading." << std::endl;
        return;
    }

    file.close();
    std::cout << "Data loaded successfully." << std::endl;
}

int main() {
     try{
    while (true) {
        displayMainMenu();
        int choice;
        std::cin >> choice;
        std::cin.ignore();
      
        switch (choice) {
            case 1: {
                // Implement code to add a new inpatient
                std::string name;
                int age, roomNumber;
                std::cout << "Enter patient name: ";
                std::cin >> name;
                std::cout << "Enter patient age: ";
                std::cin >> age;
                if (age < 0 || age > 120) {
                    std::cerr << "Error: " << InvalidAgeException().what() << std::endl;
                } else {
                    std::cout << "Enter room number: (1-120)";
                    std::cin >> roomNumber;
                    patients.push_back(new Inpatient(name, age, roomNumber));
                    std:: cout << "Inpatient data is save.\n\n";
                }
                break;
            }

            case 2: {
                // Implement code to add a new outpatient
                std::string name, appointmentDate;
                int age;
                std::cout << "Enter patient name: ";
                std::cin >> name;
                std::cout << "Enter patient age: ";
                std::cin >> age;
                if (age < 0 || age > 120) {
                    std::cerr << "Error: " << InvalidAgeException().what() << std::endl;
                } else {
                    std::cout << "Enter appointment date: ";
                    std::cin >> appointmentDate;
                    patients.push_back(new Outpatient(name, age, appointmentDate));
                    std:: cout << "Outpatient data is save.\n\n";
                }
                break;
            }

            case 3:if (patients.empty() || med_staff.empty()) {
        std::cout << "Data not loaded. Load data first." << std::endl;
        loadDataFromFile(); // Function to load data from a file
    }

    scheduleAppointment(patients, med_staff); // Function to schedule an appointment
    break;

            case 4:
                manageMedicalStaff();
                break;

            case 5: {
                // Implement code to display patient records
                for (const Patient* patient : patients) {
                    patient->displayInfo();
                    std::cout << "\n";
                }
                break;
            }

            case 6: {
                std::ofstream file("hospital_data.txt");
                if (file.is_open()) {
                // Writing patient data
                for (const auto& patient : patients) {
                   file << "Patient;" << patient->getName() << ";" << patient->getAge() << "\n";
                }

                // Writing medical staff data
                for (const auto& staff : med_staff) {
                    file << "Staff;" << staff->getName() << ";" << staff->getSpecialty() << "\n";
                }

                // Writing appointment data
                for (size_t i = 0; i < appointments.size(); ++i) {
            file << "Appointment;" << appointments[i]->getPatientName(i) << ";" 
                 << appointments[i]->getStaffName(i) << ";" << appointments[i]->getDate(i) 
                 << ";" << appointments[i]->getTime(i) << "\n";
        }

        file.close();
        std::cout << "Data saved to hospital_data.txt" << std::endl;
    } else {
        std::cerr << "Unable to open file..." << std::endl;
    }
    break;
    }

            case 7:
                {
    std::ifstream file("hospital_data.txt");
    if (!file.is_open()) {
        std::cerr << "Unable to open file for reading." << std::endl;
    } else {
        // Logic to read data from file
        file.close();
        std::cout << "Data loaded successfully." << std::endl;
    }
    break; // Add the missing break statement
    }

            case 8:
                // Clean up dynamically allocated objects
                for (Patient* patient : patients) {
                    delete patient;
                }
                patients.clear();
                std::cout << "Exiting the system. Goodbye!\n";
                return 0;

            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
            
            }
    }
 } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}

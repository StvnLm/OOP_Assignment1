#include "../header/inpatient.h"
#include <string>

using namespace std;

Inpatient::Inpatient() : room_number(0), services_required() {
}

Inpatient::Inpatient(string name, int age, char gender, string ailment, int rn, vector<Patient_services>& services) :
 										 Patient(name, age, gender, ailment), services_required(services), room_number(rn) {
}

bool Inpatient::set_room_number(int n) {
	room_number = n;
	return room_number > 0;
}

bool Inpatient::set_services_required(vector<Patient_services> n) {
	services_required = n;
	return services_required.size() > 0;
}

int Inpatient::get_room_number() {
	return room_number;
};

vector<Patient_services> Inpatient::get_services_required() {
	return services_required;
}

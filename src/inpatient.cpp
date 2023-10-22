#include "../header/inpatient.h"

using namespace std;

Inpatient::Inpatient() : room_number(0), services_required() {
}

Inpatient::Inpatient(int rn, list<Patient_services> sr) : room_number(rn), services_required(sr) {
}

bool Inpatient::set_room_number(int n) {
	room_number = n;
	return room_number > 0;
}

bool Inpatient::set_services_required(list<Patient_services> n) {
	services_required = n;
	return !services_required.empty();
}

int Inpatient::get_room_number() {
	return room_number;
};

list<Patient_services> Inpatient::get_services_required() {
	return services_required;
}

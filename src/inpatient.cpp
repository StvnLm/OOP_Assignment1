#include "../header/inpatient.h"

using namespace std;

Inpatient::Inpatient() : room_number(0), services_required() {
}

Inpatient::Inpatient(int room_number, list<Patient_services> services_required) : {
	this->room_number = room_number;
	this->services_required = services_required;
}

bool set_room_number

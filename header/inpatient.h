#pragma once
#ifndef INPATIENT_H
#define INPATIENT_H

#include "patient.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;

struct Patient_services {
	string service_name;
	string dose_schedule;
	string start_date;
	string end_date;
};

class Inpatient : public Patient {
public:
	Inpatient();
	Inpatient(int room_number, list<Patient_services> n);
	bool set_room_number(int n);
	bool set_services_required(list<Patient_services> n);
	int get_room_number();
	list<Patient_services> get_services_required();
private:
	list<Patient_services> services_required;
	int room_number;
};

#endif
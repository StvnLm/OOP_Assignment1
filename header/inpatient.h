#pragma once
#ifndef INPATIENT_H
#define INPATIENT_H

#include "patient.h"
#include <iostream>
#include <string>
//#include <list>
#include <vector>

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
	Inpatient(string name, int age, char gender, string ailment, int room_number, vector<Patient_services>& services);
	bool set_room_number(int n);
	bool set_services_required(vector<Patient_services> n);
	int get_room_number();
	vector<Patient_services> get_services_required();
private:
	vector<Patient_services> services_required;
	int room_number;
};

#endif
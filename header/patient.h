#pragma once
#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>
using namespace std;

class Patient {
public:
	Patient();
	~Patient();
	void get_patient_info();
	bool set_name(string n);
	bool set_gender(string n);
	bool set_age(int n);
	bool set_address(string n);
	bool set_phone_number(string n);

private:
	string name;
	string gender;
	int age;
	string address;
	string phone_number;
};

#endif
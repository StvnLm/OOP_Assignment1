#pragma once
#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>
#include <tuple>

using namespace std;

class Patient {
public:
	Patient();
	~Patient();
	Patient(string name, int age, char gender);
	tuple<string, char, int> get_patient_info();
	bool set_name(string n);
	bool set_gender(char n);
	bool set_location(string n);
	bool set_age(int n);
	bool set_ailment(string n);
	string get_name();
	char get_gender();
	string get_location();
	int get_age();
	string get_ailment();
private:
	string name;
	char gender;
	int age;
	string location = "";
	string ailment;
};

#endif
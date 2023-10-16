#pragma once
#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>
#include <tuple>

using namespace std;

class Patient {
public:
	Patient(string name, int age, char gender);
	~Patient();
	tuple<string, string, int> get_patient_info();
	bool set_name(string n);
	bool set_gender(char n);
	bool set_age(int n);
	string get_name();
	string get_gender();
	int get_age();

private:
	string name;
	string gender;
	int age;
};

#endif
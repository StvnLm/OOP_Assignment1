#pragma once

#ifndef MED_STAFF_H
#define MED_STAFF_H

#include<iostream>
#include<string>

using namespace std;

class MedicalStaff
{
protected:
	string name;
	string specialty;
	bool availability = true; //<-- this and related functions will probably be altered so multiple appointments at different times are possible for one staff member
public:
	MedicalStaff(string n, string s)
	{
		name = n;
		specialty = s;
	}

	void changeAvailability()
	{
		availability = false;
	}

	string getName() const
	{
		return name;
	}

	string getSpecialty() const
	{
		return specialty;
	}

	bool getAvailability() const
	{
		return availability;
	}
};

class Doctor : public MedicalStaff
{
public:
	Doctor(string n, string s) : MedicalStaff(n, s)
	{

	}
};

class Nurse : public MedicalStaff
{
public:
	Nurse(string n, string s) : MedicalStaff(n, s)
	{

	}
};
#endif

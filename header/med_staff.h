#pragma once

#ifndef MED_STAFF_H
#define MED_STAFF_H

#include<iostream>
#include<string>
#include<vector>
#include<array>

using namespace std;

class MedicalStaff
{
protected:
	string name;
	string specialty;
	vector <array<int, 3>> schedule;
public:
	MedicalStaff(string n, string s)
	{
		name = n;
		specialty = s;
	}

	bool checkAvailability(int d, int h, int m)
	{
		for (int i = 0; i < schedule.size(); i++)
		{
			if (schedule[i][0] == d && schedule[i][1] == h && schedule[i][2] == m) return false; //if scheduled date already exists
		}
		schedule.push_back({ {d, h, m} });
		return true;
	}

	string getName() const
	{
		return name;
	}

	string getSpecialty() const
	{
		return specialty;
	}

	void displaySchedule() const
	{
		for (int i = 0; i < schedule.size(); i++)
		{
			cout << "\n" << "on day " << schedule[i][0] << " at " << schedule[i][1] << ":" << schedule[i][2];
		}
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

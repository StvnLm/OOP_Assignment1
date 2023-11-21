#include<iostream>
#include<string>
#include<map>
#include"med_staff.h"

using namespace std;

int main()
{
	map<string, MedicalStaff*> staff;
	string appoint;

	staff = { {"Jake", new Doctor("Jake", "Neurologist")}, 
			{"Kyle", new Doctor("Kyle", "Surgeon")},
			{"Sasha", new Nurse("Sasha", "Critical Care")},
			{"Taylor", new Nurse("Taylor", "Dermatologist")},
			{"Jordan", new Nurse("Jordan", "Cardiac Nursing")}, 
			{"Shane", new Nurse("Shane", "Obstetrics")},
			{"Zella", new Nurse("Zella", "Intensive Care Medicine")},
			{"Patrica", new Doctor("Patrica", "Anesthesiology")},
			{"Alexander", new Doctor("Alexander", "Emergency Medicine")} };

	for (auto it = staff.cbegin(); it != staff.cend(); ++it) //for displaying all staff members
	{
		std::cout << it->first << ": " << it->second->getSpecialty() << "\n";
	}
	try {
		cout << "Enter name of who you want to assign to the appointment" << endl;
		cin >> appoint;

		if (staff[appoint] == NULL) throw 1; //if input string doesn't match with an object
		else if (staff[appoint]->getAvailability())
		{
			cout << staff[appoint]->getName() << endl;
			cout << staff[appoint]->getSpecialty() << endl;
		}
		else cout << "Selected staff member is currently unavailable for this time. Someone else must be selected." << endl;
	}
	catch(int errorint)
	{
		cout << "==========\nError: " << errorint << "\nnot a registered name, or entered incorrectly, proper capitalization is required.\n==========" << endl;
	}
	return 0;
}
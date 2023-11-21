#include<iostream>
#include<string>
#include<map>
#include"med_staff.h"

using namespace std;

int main()
{
	map<string, MedicalStaff*> staff;
	string appoint;
	int day, hour, min;

	staff = { {"Jake", new Doctor("Jake", "Neurologist")}, 
			{"Kyle", new Doctor("Kyle", "Surgeon")},
			{"Sasha", new Nurse("Sasha", "Critical Care")},
			{"Taylor", new Nurse("Taylor", "Dermatologist")},
			{"Jordan", new Nurse("Jordan", "Cardiac Nursing")}, 
			{"Shane", new Nurse("Shane", "Obstetrics")},
			{"Zella", new Nurse("Zella", "Intensive Care Medicine")},
			{"Patrica", new Doctor("Patrica", "Anesthesiology")},
			{"Alexander", new Doctor("Alexander", "Emergency Medicine")} };
	while (true)
	{
		for (auto it = staff.cbegin(); it != staff.cend(); ++it) //for displaying all staff members
		{
			std::cout << it->first << ": " << it->second->getSpecialty() << endl;
		}
		try {
			cout << "\nEnter name of who you want to assign to the appointment or q to exit" << endl;
			cin >> appoint;
			if (appoint == "q") break; 
			else if (staff[appoint] == NULL) throw 1; //if input string doesn't match with an object
			cout << "Enter the time for the appointment in day/hour/miunte" << endl;
			cout << "day: ";
			cin >> day;
			cout << "hour: ";
			cin >> hour;
			cout << "minute: ";
			cin >> min;
			cout << "\n";

			if (staff[appoint]->checkAvailability(day, hour, min))
			{
				cout << "new appointment with: ";
				cout << staff[appoint]->getName() << endl;
				cout << "on day " << day << " at " << hour << ":" << min << "\n\n";
			}
			else 
			{
				cout << "Selected staff member is currently unavailable for this time. they're already scheduled for these time(s):" << endl;
				staff[appoint]->displaySchedule();
				cout << "Someone else or another time must be selected.\n\n";
			}
		}
		catch (int errorint)
		{
			cout << "==========\nError: " << errorint << "\nnot a registered name, or entered incorrectly, proper capitalization is required.\n==========\n\n";
		}
	}
	return 0;
}

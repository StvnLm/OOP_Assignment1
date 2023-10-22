#include "../header/patient.h"
#include <tuple>

using namespace std;

//Patient(string name, int age, char gender);

Patient::Patient() : name("Jane Doe"),  age(0),  gender('N'), ailment("NONE") {
}

Patient::Patient(string n, int a, char g) : name(n), age(a), gender(g) {
}

Patient::~Patient() {
}

tuple<string, char, int> Patient::get_patient_info() {
	return make_tuple(this->name, this->gender, this->age);
}

bool Patient::set_name(string name) {
	this->name = name;
	return name.size() > 0;
}

bool Patient::set_gender(char gender) {
	this->gender = gender;
	return (tolower(gender) == 'm' || tolower(gender) == 'f');
}

bool Patient::set_age(int age) {
	this->age = age;
	return age > 0;
}

bool Patient::set_location(string location) {
	this->location = location; 
	return this->location == "";
}


bool Patient::set_ailment(string ailment) {
	this->ailment = ailment;
	return this->ailment == "";
}

string Patient::get_name() {
	return this->name;
}
char Patient::get_gender() {

	return this->gender;
}
int Patient::get_age() {
	return this->age;
}

string Patient::get_ailment() {
	return this->ailment;
}

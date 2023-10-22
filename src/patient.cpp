#include "../header/patient.h"
#include <tuple>

using namespace std;

Patient::Patient() : name(""),  age(0),  gender("") {
}

Patient::Patient(string name, int age, char gender) {
	this->name = name;
	this->age = age;
	this->gender = gender;
	this->location = "";
}

Patient::~Patient() {
	// EmptyDeconstructor
}

tuple<string, string, int> Patient::get_patient_info() {
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

string Patient::get_name() {
	return this->name;
}
string Patient::get_gender() {
	return this->gender;
}
int Patient::get_age() {
	return this->age;
}


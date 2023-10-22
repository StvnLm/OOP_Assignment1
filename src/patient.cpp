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
	return make_tuple(name, gender, age);
}

bool Patient::set_name(string n) {
	name = n;
	return name.size() > 0;
}

bool Patient::set_gender(char g) {
	gender = g;
	return (tolower(gender) != 'm' || tolower(gender) != 'f');
}

bool Patient::set_age(int a) {
	age = a;
	return age > 0;
}

bool Patient::set_location(string l) {
	location = l; 
	return location != "";
}

bool Patient::set_ailment(string a) {
	ailment = a;
	return ailment != "";
}

string Patient::get_name() {
	return name;
}
char Patient::get_gender() {
	return gender;
}
int Patient::get_age() {
	return age;
}

string Patient::get_ailment() {
	return ailment;
}

string Patient::get_location() {
	return location;
}
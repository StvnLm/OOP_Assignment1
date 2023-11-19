// main.cpp
#include "../header/patient.h" // Include the header file
#include <iostream>
#include <string>
#include <tuple>

using namespace std;

int main() {
    Patient patient("Steven", 12, 'M');
    cout << patient.get_age();
    patient.set_age(-2);
    return 0;
}

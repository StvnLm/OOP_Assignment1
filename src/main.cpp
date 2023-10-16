// main.cpp
#include "../header/patient.h" // Include the header file
#include <iostream>
#include <string>
using namespace std;

int main() {
    Patient patient("Steven", 12, 'M');
    cout << patient.get_age();
    return 0;
}
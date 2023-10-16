#include <gtest/gtest.h>
#include "../header/patient.h"
#include "../src/patient.cpp"
#include <string>

// Parameters
// PatientTest: Name of the test Suite
// GetName: Name of the unit test
TEST(PatientTest, GetName) {
	Patient patient("John", 30, 'M');
}

TEST(PatientTest, SetAge) {
    Patient patient("Alice", 25, 'F');
    EXPECT_TRUE(patient.set_age(26));
    EXPECT_EQ(patient.get_age(), 26);
}
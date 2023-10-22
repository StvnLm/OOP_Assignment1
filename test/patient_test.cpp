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

TEST(PatientTest, setPatientValues) {
	Patient patient;
	EXPECT_TRUE(patient.set_name("Jane Doe"));
	EXPECT_TRUE(patient.set_age(100));
	EXPECT_TRUE(patient.set_gender('F'));
	EXPECT_TRUE(patient.set_location("100 Bay street, Toronto, Ontario, L5X 2A8"));
	EXPECT_TRUE(patient.set_ailment("Broken bones"));
	EXPECT_EQ(patient.get_name(), "Jane Doe");
	EXPECT_EQ(patient.get_age(), 100);
	EXPECT_EQ(patient.get_gender(), 'F');
	EXPECT_EQ(patient.get_location(), "100 Bay street, Toronto, Ontario, L5X 2A8");
	EXPECT_EQ(patient.get_ailment(), "Broken bones");
}
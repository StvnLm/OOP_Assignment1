#include <gtest/gtest.h>
#include "../header/patient.h"
#include "../src/patient.cpp"
#include <string>

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
#include <gtest/gtest.h>
#include "../header/inpatient.h"
#include "../src/inpatient.cpp"
#include <string>

TEST(InpatientTest, setInpatientValues) {
	Inpatient inpatient;
	vector<Patient_services> list_of_services_required;

	Patient_services flu_immunization;
	flu_immunization.service_name = "Fluzone High-Dose Quadrivalent vaccine";
	flu_immunization.dose_schedule = "Once a year";
	flu_immunization.start_date = "Sept 30 2023";
	flu_immunization.end_date = "Sept 30 2023";
	list_of_services_required.push_back(flu_immunization);
	Patient_services ear_drops;
	ear_drops.service_name = "Pramox-HC Corticosteroid ear drops";
	ear_drops.dose_schedule = "Twice a day";
	ear_drops.start_date = "November 1 2023";
	ear_drops.end_date = "November 14 2023";
	list_of_services_required.push_back(ear_drops);

	EXPECT_TRUE(inpatient.set_name("Jane Doe"));
	EXPECT_TRUE(inpatient.set_room_number(123));
	EXPECT_TRUE(inpatient.set_services_required(list_of_services_required));

	EXPECT_EQ(inpatient.get_name(), "Jane Doe");
	EXPECT_EQ(inpatient.get_room_number(), 123);
	Patient_services flu_info = inpatient.get_services_required()[0];
	Patient_services ear_info = inpatient.get_services_required()[1];
	EXPECT_EQ(flu_info.service_name, "Fluzone High-Dose Quadrivalent vaccine");
	EXPECT_EQ(flu_info.start_date, "Sept 30 2023");
	EXPECT_EQ(ear_info.service_name, "Pramox-HC Corticosteroid ear drops");
	EXPECT_EQ(ear_info.dose_schedule, "Twice a day");
	EXPECT_EQ(ear_info.end_date, "November 14 2023");
}
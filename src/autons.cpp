#include "main.h"
#include "lemlib/api.hpp"
#include "lemlib/logger/stdout.hpp"
#include "Region-config.h"
#include "pros/adi.hpp"


	// Close paths
	ASSET(Close1_txt);
	ASSET(Close2_txt);
void Close() {
	//init stuff
    pros::lcd::clear_line(1);
	int auto_v; 
	auto_v = floor(auto_select.get_value() /750);
	pros::lcd::print(1, "Pot auto:%d", auto_v);
	pros::lcd::print(6, "Close side auto");

	//actual code
	chassis.setPose(-40.53,-63.889,0);
	chassis.follow(Close1_txt,10,5000);
	chassis.waitUntil(42);
	wings.set_value(true);
	chassis.waitUntilDone();
	wings.set_value(false);
	// pros::delay(250);
	// chassis.follow(Close2_txt,13,5000,false);
}

	//Far paths
	ASSET(Far1_txt);
	ASSET(Far2_txt);
	ASSET(Far3_txt);
void far() {
	
	//init stuff
	pros::lcd::print(6,"Far Auto");

	//actual code
	intake.move(-100);
	chassis.setPose(-52.905,56.902,135);
	chassis.follow(Far1_txt, 13,4000);
	chassis.waitUntilDone();
	chassis.setPose(-5.466,-0.206,90);
	pros::delay(250);
	chassis.turnTo(-30,4,1500);
	chassis.waitUntilDone();
	intake.move(100);
	wings.set_value(true);
	chassis.moveToPose(-38,0,270,2000);
	chassis.waitUntilDone();
	wings.set_value(false);
	chassis.moveToPoint(0,0,100,false);
	chassis.waitUntilDone();
	chassis.turnTo(-6,23.514,1000);
	intake.move(-100);
	chassis.moveToPoint(-10.88,23.771,2000);
	chassis.waitUntilDone();
	chassis.turnTo(-54,34,1000);
	chassis.waitUntilDone();
	chassis.setPose(-10,30,277);
	chassis.follow(Far3_txt,11,5000);
	chassis.waitUntil(25);
	intake.move(100);
	chassis.waitUntilDone();
	chassis.moveToPoint(-65,60,500,false);

	
}	
	//skills paths
	ASSET(skillsAuto1_txt);
	ASSET(skillsAuto2_txt);
	ASSET(skillsAuto3_txt);
void skills() {
   
	int auto_v; 
	auto_v = floor(auto_select.get_value() /750);
	pros::lcd::print(2, "Pot auto:%d", auto_v);
	pros::lcd::print(6, "skills auto");
	Cata.move_voltage(11000);
	pros::delay(1000);
	Cata.move_voltage(0);
	chassis.setPose(-46.718,-62.6,50);
    chassis.follow(skillsAuto1_txt,10,10000);
    chassis.waitUntilDone();
	pros::delay(500);
	chassis.follow(skillsAuto2_txt,10,10000,false);
	chassis.waitUntilDone();
	chassis.setPose(3,-4,180);
	pros::delay(500);
	chassis.follow(skillsAuto3_txt,10,3000);
	chassis.waitUntil(12);
	wings.set_value(true);
}

	//bracket close paths
void Bracket_Close() {
	pros::lcd::print(6, "B-Close");

}

	//bracket far paths 
void Bracket_Far() {
	pros::lcd::print(6, "B-Far");
}
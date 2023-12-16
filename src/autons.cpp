#include "main.h"
#include "lemlib/api.hpp"
#include "lemlib/logger/stdout.hpp"
#include "Region-config.h"
#include "pros/adi.hpp"

	ASSET(Close1_txt);
void Close() {
	//init stuff
    pros::lcd::clear_line(1);
	int auto_v; 
	auto_v = floor(auto_select.get_value() /750);
	pros::lcd::print(1, "Pot auto:%d", auto_v);
	pros::lcd::print(2, "Close side auto");

	//actual code
	Cata.move_relative(200,100);
	chassis.setPose(-47.749,-54.865,25);
	chassis.follow(Close1_txt,10,15000);
	
}

	ASSET(Far1_txt);
	ASSET(Far2_txt);
void far() {
	//init stuff
    
	int auto_v; 
	auto_v = floor(auto_select.get_value() /750);
	pros::lcd::print(1, "Pot auto:%d", auto_v);
	pros::lcd::print(2, "far side auto");

	//actual code
	Cata.move_relative(500,100);
	chassis.follow(Far1_txt, 10, 7000);
	chassis.follow(Far2_txt, 10, 8000, false);
	

}

	ASSET(skillsAuto1_txt);
void skills() {
   
	int auto_v; 
	auto_v = floor(auto_select.get_value() /750);
	pros::lcd::print(2, "Pot auto:%d", auto_v);
	pros::lcd::print(2, "skills auto");
	chassis.setPose(-51.616,-56.67,225);
    chassis.follow(skillsAuto1_txt, 20  , 15000,false);
    chassis.waitUntilDone();
}
void nothing() {
	int auto_v; 
	auto_v = floor(auto_select.get_value() /750);
	pros::lcd::print(2, "Pot auto:%d", auto_v);
	pros::lcd::print(2, "No auto");
}
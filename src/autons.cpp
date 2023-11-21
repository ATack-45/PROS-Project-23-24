#include "main.h"
#include "ARMS/config.h"
#include "Region-config.h"
#include "pros/adi.hpp"

void Close() {
	//init stuff
    pros::lcd::clear();
	int auto_v; 
	auto_v = floor(auto_select.get_value() /750);
	pros::lcd::print(1, "Pot auto:%d", auto_v);
	pros::lcd::print(2, "Close side auto");

	//actual code
	Cata.move_relative(100,100);
	arms::chassis::turn(60,75);
	arms::chassis::move(10);
	wings.set_value(true);
	pros::delay(250);
	arms::chassis::move(-15, arms::REVERSE);
	wings.set_value(false);
	arms::chassis::turn(160);
	pros::delay(250);
	arms::chassis::turn(270);
	arms::chassis::move(5);
	intake.move(-100);
	arms::chassis::turn(300);
	arms::chassis::move(20);
	arms::chassis::turn(340);

	

	

	
	


	
}
void far() {
	//init stuff
    pros::lcd::clear();
	int auto_v; 
	auto_v = floor(auto_select.get_value() /750);
	pros::lcd::print(1, "Pot auto:%d", auto_v);
	pros::lcd::print(2, "far side auto");

	//actual code
	
	arms::chassis::turn(315);
	arms::chassis::move(-35, arms::REVERSE);
	arms::chassis::move(10);
	


	


	
	

	



	

}
void skills() {
    pros::lcd::clear();
	int auto_v; 
	auto_v = floor(auto_select.get_value() /750);
	pros::lcd::print(2, "Pot auto:%d", auto_v);
	pros::lcd::print(2, "skills auto");
	pros::lcd::print(1, "ARMS Error:%d", arms::odom::getDistanceError);	
	Cata.move(100);
}
void nothing() {
   pros::lcd::clear();
	int auto_v; 
	auto_v = floor(auto_select.get_value() /750);
	pros::lcd::print(2, "Pot auto:%d", auto_v);
	pros::lcd::print(2, "No auto");
}
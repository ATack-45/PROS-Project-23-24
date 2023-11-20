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
	arms::chassis::move({44,0});
	arms::chassis::turn(255);
	wings.set_value(true);
	intake.move(-100);
	arms::chassis::move(26);
	arms::chassis::move(-12, arms::REVERSE);
	intake.move(0);
	arms::chassis::turn(140,75);
	wings.set_value(false);
	arms::chassis::move(45.25);
	arms::chassis::turn(-332,75);
	arms::chassis::move(10);
	arms::chassis::turn(-340);
	wings.set_value(true);
	pros::delay(250);
	arms::chassis::move(-15, arms::REVERSE);
	arms::chassis::turn(-311);
	wings.set_value(false);
	pros::delay(250);
	arms::chassis::move(-5, arms::REVERSE);
	arms::chassis::turn(250);
	arms::chassis::move(13);
	intake.move(-100);
	arms::chassis::turn(270);
	arms::chassis::move(6);
	

	
	


	
}
void far() {
	//init stuff
    pros::lcd::clear();
	int auto_v; 
	auto_v = floor(auto_select.get_value() /750);
	pros::lcd::print(1, "Pot auto:%d", auto_v);
	pros::lcd::print(2, "far side auto");

	//actual code
	Cata.move_relative(500,100);
	intake.move(-100);
	arms::chassis::turn(30);
	arms::chassis::move(45);
	intake.move(100);


	


	
	

	



	

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
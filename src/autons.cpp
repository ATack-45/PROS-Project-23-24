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
	Cata.move_relative(200,100);
	wings.set_value(true);
	pros::delay(300);
	arms::chassis::turn(90);
	
	pros::delay(250);
	arms::chassis::turn(330);
	arms::chassis::move(15);
	arms::chassis::turn(270);
	arms::chassis::move(20);
	arms::chassis::turn(300);

}
void far() {
	//init stuff
    pros::lcd::clear();
	int auto_v; 
	auto_v = floor(auto_select.get_value() /750);
	pros::lcd::print(1, "Pot auto:%d", auto_v);
	pros::lcd::print(2, "far side auto");
	arms::odom::imu.reset();

	//actual code
	Cata.move_relative(500,100);
	arms::chassis::move(43);
	arms::chassis::turn(270);
	intake.move(-100);
	arms::chassis::move(5);
	intake.move(0);
	arms::chassis::move(-30,75,  arms::REVERSE);
	wings.set_value(true);
	pros::delay(600);
	arms::chassis::move(32);
	pros::delay(250);
	arms::chassis::move(-20,75,  arms::REVERSE);
	wings.set_value(false);
	arms::chassis::turn(45);
	intake.move(100);
	arms::chassis::move(10,33);
	arms::chassis::move(-8,33,arms::REVERSE);
	arms::chassis::turn(270);
	intake.move(-100);
	wings.set_value(true);
	arms::chassis::move(20);
	arms::chassis::move(-15,arms::REVERSE);
	arms::chassis::turn(260);
	arms::chassis::move(15);
	arms::chassis::move(-15,arms::REVERSE);
	wings.set_value(false);
	intake.move(0);


	
	


	


	
	

	



	

}
void skills() {
    pros::lcd::clear();
	int auto_v; 
	auto_v = floor(auto_select.get_value() /750);
	pros::lcd::print(2, "Pot auto:%d", auto_v);
	pros::lcd::print(2, "skills auto");
	pros::lcd::print(1, "ARMS Error:%d", arms::odom::getDistanceError);	
	Cata.move(85);
}
void nothing() {
   pros::lcd::clear();
	int auto_v; 
	auto_v = floor(auto_select.get_value() /750);
	pros::lcd::print(2, "Pot auto:%d", auto_v);
	pros::lcd::print(2, "No auto");
}
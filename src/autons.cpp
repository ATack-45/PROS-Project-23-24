#include "main.h"
#include "ARMS/config.h"
#include "Region-config.h"
#include "pros/adi.hpp"

void Close() {
	pros::lcd::clear();
	int auto_v; 
	auto_v = floor(auto_select.get_value() /750);
	pros::lcd::print(2, "Pot auto:%d", auto_v);
	pros::lcd::print(2, "Clothes line auto");
	pros::lcd::print(1, "ARMS Error:%d", arms::odom::getDistanceError);	
	Cata.move(100);
}
void far() {
	//init stuff
    pros::lcd::clear();
	int auto_v; 
	auto_v = floor(auto_select.get_value() /750);
	pros::lcd::print(2, "Pot auto:%d", auto_v);
	pros::lcd::print(2, "far side auto");

	//pos = left 10", 2" 
	//actual code
	arms::chassis::turn(-35);
	arms::chassis::move(-36, arms::REVERSE);// push alliance in
	arms::chassis::move({-15,0}, 75);// use odometry here incase hitting goal knocks us at a weird angle
	arms::chassis::turn(-158,75);//orient towards 2nd triball
	arms::chassis::move(48, 75, arms::ASYNC);//move to second triball
	pros::delay(1200);
	intake.move(100);
	pros::delay(100);
	arms::chassis::turn(-270,75);// orient towards goal
	intake.move(-127);
	arms::chassis::move(10, 75, arms::THRU); // score 2nd triball
	pros::delay(400);
	arms::chassis::move(-12, arms::REVERSE);
	intake.move(0);
	arms::chassis::turn(-105,50); // orient towards 3rd triball
	intake.move(127);
	arms::chassis::move(10, 75); // move to 3rd triball
	pros::delay(150);
	arms::chassis::turn(90,50); // orient towards goal
	arms::chassis::move(23, 90, arms::ASYNC); // score 3rd triball
	intake.move(-127);
	pros::delay(1200);
	arms::chassis::move(-10, arms::REVERSE);
	intake.move(0);
	arms::chassis::turn(-34, 75); // orient toward 4th triball
	intake.move(127);
	arms::chassis::move(22, 75); // move to 4th triball
	pros::delay(400);
	arms::chassis::move(-12, arms::REVERSE);
	arms::chassis::turn(90,50); // orient towards goal
	arms::chassis::move(14, 75, arms::THRU); // score 4th triball
	intake.move(-127);
	pros::delay(500);
	arms::chassis::move(-10, arms::REVERSE);



	
	

	



	

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
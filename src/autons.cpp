#include "main.h"
#include "ARMS/config.h"
#include "Region-config.h"
#include "pros/adi.hpp"

void Close() {
	pros::lcd::clear();
	int auto_v; 
	auto_v = floor(auto_select.get_value() /750);
	pros::lcd::print(2, "Pot auto:%d", auto_v);
	pros::lcd::print(1, "ARMS Error:%d", arms::odom::getDistanceError);	
	Cata.move(100);
}
void far() {
    while (true)
		{
			pros::lcd::print(1, "ARMS Error:%d", arms::odom::getDistanceError);
		}
	arms::chassis::move(1);
}
void skills() {
    while (true)
		{
			pros::lcd::print(1, "ARMS Error:%d", arms::odom::getDistanceError);
		}
	arms::chassis::move(1);
}
void nothing() {
   
}
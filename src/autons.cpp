#include "main.h"
#include "ARMS/config.h"
#include "Region-config.h"
#include "pros/adi.hpp"

void Close() {
    while (true)
		{
			pros::lcd::print(1, "ARMS Error:%d", arms::odom::getDistanceError);
		}
	arms::chassis::move(1);
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
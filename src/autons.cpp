#include "main.h"
#include "lemlib/api.hpp"
#include "lemlib/logger/stdout.hpp"
#include "Region-config.h"
#include "pros/adi.hpp"

void Close() {
	//init stuff
    pros::lcd::clear_line(1);
	int auto_v; 
	auto_v = floor(auto_select.get_value() /750);
	pros::lcd::print(1, "Pot auto:%d", auto_v);
	pros::lcd::print(2, "Close side auto");

	//actual code
	Cata.move_relative(200,100);
	
}
void far() {
	//init stuff
    
	int auto_v; 
	auto_v = floor(auto_select.get_value() /750);
	pros::lcd::print(1, "Pot auto:%d", auto_v);
	pros::lcd::print(2, "far side auto");

	//actual code
	Cata.move_relative(500,100);
	

}
void skills() {
   
	int auto_v; 
	auto_v = floor(auto_select.get_value() /750);
	pros::lcd::print(2, "Pot auto:%d", auto_v);
	pros::lcd::print(2, "skills auto");
	Cata.move(100);
}
void nothing() {
	int auto_v; 
	auto_v = floor(auto_select.get_value() /750);
	pros::lcd::print(2, "Pot auto:%d", auto_v);
	pros::lcd::print(2, "No auto");
}
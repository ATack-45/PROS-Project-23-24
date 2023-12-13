#include "main.h"
#include "lemlib/chassis/chassis.hpp"
#include "lemlib/pid.hpp"


extern pros::Motor intake;
extern pros::Motor Cata;
extern pros::adi::DigitalOut wings;
extern pros::Rotation cata_track;
extern pros::adi::Potentiometer drive_select;
extern pros::adi::Potentiometer auto_select;
extern pros::Rotation T_wheel;
extern pros::adi::DigitalOut blocka;
extern pros::adi::DigitalOut hang;
extern pros::Distance ball_sensor;
extern pros::IMU IMU;
extern lemlib::Drivetrain drivetrain;
extern lemlib::TrackingWheel horizontal;
extern lemlib::OdomSensors sensors;
extern lemlib::ControllerSettings lateralController;
extern lemlib::ControllerSettings angularController;
extern lemlib::Chassis chassis;

void Close();
void far();
void skills();
void nothing();
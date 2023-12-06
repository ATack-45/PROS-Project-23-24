#include "main.h"


extern pros::Motor intake;
extern pros::Motor Cata;
extern pros::ADIDigitalOut wings;
extern pros::Rotation cata_track;
extern pros::ADIPotentiometer drive_select;
extern pros::ADIPotentiometer auto_select;
extern pros::Rotation T_wheel;
extern pros::ADIDigitalOut blocka;
extern pros::ADIDigitalOut hang;
extern pros::Distance ball_sensor;
extern pros::IMU IMU;
extern lemlib::Drivetrain drivetrain;
extern lemlib::TrackingWheel horizontal;
extern lemlib::OdomSensors sensors;
extern lemlib::ControllerSettings lateralController;
extern lemlib::ControllerSettings angularController;
extern lemlib::Chassis chassis;
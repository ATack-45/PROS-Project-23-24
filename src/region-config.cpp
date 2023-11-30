#include "Region-config.h"



pros::Motor lF(1, pros::E_MOTOR_GEARSET_06, false); // port 1, blue gearbox, not reversed
pros::Motor lM(1, pros::E_MOTOR_GEARSET_06, false); // port 1, blue gearbox, not reversed
pros::Motor lB(1, pros::E_MOTOR_GEARSET_06, false); // port 1, blue gearbox,  reversed
pros::Motor rF(1, pros::E_MOTOR_GEARSET_06, false); // port 1, blue gearbox, not reversed
pros::Motor rM(1, pros::E_MOTOR_GEARSET_06, false); // port 1, blue gearbox, not reversed
pros::Motor rB(1, pros::E_MOTOR_GEARSET_06, false); // port 1, blue gearbox,  reversed

pros::Motor intake(5);
pros::Motor Cata(-4);
pros::ADIDigitalOut wings(1);
pros::Rotation cata_track (7);
pros::ADIPotentiometer drive_select(3);
pros::ADIPotentiometer auto_select (4);
pros::ADIDigitalOut T_wheel(6);
pros::ADIDigitalOut blocka(5);
pros::ADIDigitalOut hang(6);
pros::Distance ball_sensor(19);

pros::MotorGroup left_side_motors()

 

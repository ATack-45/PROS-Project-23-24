#include "Region-config.h"
#include "lemlib/chassis/chassis.hpp"
#include "lemlib/pid.hpp"



pros::Motor lF(-20, pros::v5::MotorGears::blue); // port 1, blue gearbox, not reversed
pros::Motor lM(-19, pros::v5::MotorGears::blue); // port 1, blue gearbox, not reversed
pros::Motor lB(18, pros::v5::MotorGears::blue); // port 1, blue gearbox,  reversed
pros::Motor rF(11, pros::v5::MotorGears::blue); // port 1, blue gearbox, not reversed
pros::Motor rM(12, pros::v5::MotorGears::blue); // port 1, blue gearbox, not reversed
pros::Motor rB(-13, pros::v5::MotorGears::blue); // port 1, blue gearbox,  reversed


pros::Motor intake(2);
pros::Motor Cata(1);
pros::adi::DigitalOut wings(5);
pros::Rotation cata_track (10);
pros::adi::Potentiometer drive_select(1);
pros::adi::Potentiometer auto_select (3);
pros::Rotation T_wheel(17);
pros::adi::DigitalOut blocka(4);
pros::adi::DigitalOut hang(6);

pros::Imu IMU(16 );

pros::MotorGroup left_motors({-20,-19,18}, pros::v5::MotorGears::blue, pros::v5::MotorUnits::rotations);
pros::MotorGroup right_motors({11,12,-13}, pros::v5::MotorGears::blue, pros::v5::MotorUnits::rotations);


//drivetrain setup
lemlib::Drivetrain drivetrain(&left_motors, // left motor group
                              &right_motors, // right motor group
                              10.25, // 13 inch track width 
                              lemlib::Omniwheel::NEW_325, // using new 3.25" omnis
                              360, // drivetrain rpm is 360
                              2 // chase power is 2. If we had traction wheels, it would have been 8
);
lemlib::TrackingWheel horizontal(&T_wheel, 2.75, -7); 


//odom wheel setup
lemlib::OdomSensors sensors(nullptr, // vertical tracking wheel 1, set to nullptr as we don't have one
                            nullptr, // vertical tracking wheel 2, set to nullptr as we don't have one
                            &horizontal, // horizontal tracking wheel 1
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &IMU // inertial sensor
);
 
// forward/backward PID
lemlib::ControllerSettings lateralController (
    15, // kP
    50, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    5 // slew rate: Smaller number = more slew - slew = slow increase in speed
);
 
// turning PID
lemlib::ControllerSettings angularController (
    3, // kP
    19.25, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    2 // slew rate
);

lemlib::Chassis chassis(drivetrain, lateralController, angularController, sensors); 
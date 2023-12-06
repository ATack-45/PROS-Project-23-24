#include "Region-config.h"
#include "lemlib/chassis/chassis.hpp"
#include "lemlib/pid.hpp"



pros::Motor lF(-10, pros::v5::MotorGears::blue); // port 1, blue gearbox, not reversed
pros::Motor lM(-9, pros::v5::MotorGears::blue); // port 1, blue gearbox, not reversed
pros::Motor lB(8, pros::v5::MotorGears::blue); // port 1, blue gearbox,  reversed
pros::Motor rF(1, pros::v5::MotorGears::blue); // port 1, blue gearbox, not reversed
pros::Motor rM(2, pros::v5::MotorGears::blue); // port 1, blue gearbox, not reversed
pros::Motor rB(-3, pros::v5::MotorGears::blue); // port 1, blue gearbox,  reversed


pros::Motor intake(5);
pros::Motor Cata(-4);
pros::ADIDigitalOut wings(1);
pros::Rotation cata_track (7);
pros::ADIPotentiometer drive_select(3);
pros::ADIPotentiometer auto_select (4);
pros::Rotation T_wheel(6);
pros::ADIDigitalOut blocka(5);
pros::ADIDigitalOut hang(6);
pros::Distance ball_sensor(19);
pros::Imu IMU(20);

pros::MotorGroup left_motors({-10,-9,8}, pros::v5::MotorGears::blue, pros::v5::MotorUnits::rotations);
pros::MotorGroup right_motors({1,2,-3}, pros::v5::MotorGears::blue, pros::v5::MotorUnits::rotations);


//drivetrain setup
lemlib::Drivetrain drivetrain(&left_motors, // left motor group
                              &right_motors, // right motor group
                              10, // 10 inch track width -- need to change
                              lemlib::Omniwheel::NEW_325, // using new 3.25" omnis
                              360, // drivetrain rpm is 360
                              2 // chase power is 2. If we had traction wheels, it would have been 8
);
lemlib::TrackingWheel horizontal(&T_wheel, 2.75, -4.3); //need to change offset


//odom wheel setup
lemlib::OdomSensors sensors(nullptr, // vertical tracking wheel 1, set to nullptr as we don't have one
                            nullptr, // vertical tracking wheel 2, set to nullptr as we don't have one
                            &horizontal, // horizontal tracking wheel 1
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &IMU // inertial sensor
);
 
// forward/backward PID
lemlib::ControllerSettings lateralController (
    8, // kP
    30, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    5 // slew rate
);
 
// turning PID
lemlib::ControllerSettings angularController (
    4, // kP
    40, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    0 // slew rate
);

lemlib::Chassis chassis(drivetrain, lateralController, angularController, sensors); 
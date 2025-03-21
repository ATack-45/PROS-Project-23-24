#ifndef _ARMS_CONFIG_H_
#define _ARMS_CONFIG_H_

#include "ARMS/api.h"



namespace arms {

// Debug
#define ODOM_DEBUG 1

// Negative numbers mean reversed motor
#define LEFT_MOTORS -20,-19,18
#define RIGHT_MOTORS 11, 12,-13
#define GEARSET pros::E_MOTOR_GEAR_600 // RPM of chassis motors

// Ticks per inch
#define TPI   	48.604686828155517578125// Encoder ticks per inch of forward robot movement
#define MIDDLE_TPI  4206.030296875// 3300.6998Ticks per inch for the middle wheel

// Tracking wheel distances
#define TRACK_WIDTH   10.25// The distance between left and right wheels (or tracker wheels)
#define MIDDLE_DISTANCE 7 // Distance from middle wheel to the robot turning center

// Sensors
#define IMU_PORT     20 // Port 20, 0 for disabled
#define ENCODER_PORTS 0, 0, 6
#define EXPANDER_PORT 0          // Port 0 for disabled
#define ENCODER_TYPE arms::odom::EncoderType::ENCODER_ROTATION 	// The type of encoders

// Movement tuning
#define SLEW_STEP 6      // Smaller number = more slew - slew = slow increase in speed
#define LINEAR_EXIT_ERROR 1 // default exit distance for linear movements
#define ANGULAR_EXIT_ERROR 1 // default exit distance for angular movement	
#define SETTLE_THRESH_LINEAR 1     // amount of linear movement for settling
#define SETTLE_THRESH_ANGULAR 1      // amount of angular movement for settling
#define SETTLE_TIME 250   // amount of time to count as settled
#define LINEAR_KP 12
#define LINEAR_KI .025
#define LINEAR_KD 50
#define TRACKING_KP 64 // point tracking turning strength
#define ANGULAR_KP 3.0
#define ANGULAR_KI .135
#define ANGULAR_KD 19.25
#define MIN_ERROR 3      // Minimum distance to target before angular componenet is disabled
#define LEAD_PCT .675 // Go-to-pose lead distance ratio (0-1)

// Auton selector configuration constants
#define AUTONS "close", "Far", "nothing" // Names of autonomi, up to 10 -- nothing is 3, skills is 0
#define HUE 0     // Color of theme from 0-359(H part of HSV)
#define DEFAULT 3 // Default auton selected

// Initializer
inline void init() {

	chassis::init({LEFT_MOTORS}, {RIGHT_MOTORS}, GEARSET, SLEW_STEP, LINEAR_EXIT_ERROR,
	              ANGULAR_EXIT_ERROR, SETTLE_THRESH_LINEAR, SETTLE_THRESH_ANGULAR, SETTLE_TIME);

	odom::init(ODOM_DEBUG, ENCODER_TYPE, {ENCODER_PORTS}, EXPANDER_PORT, IMU_PORT,
	           TRACK_WIDTH, MIDDLE_DISTANCE, TPI,
	           MIDDLE_TPI);

	pid::init(LINEAR_KP, LINEAR_KI, LINEAR_KD, ANGULAR_KP, ANGULAR_KI, ANGULAR_KD, TRACKING_KP, MIN_ERROR, LEAD_PCT);

	const char* b[] = {AUTONS, ""};
	selector::init(HUE, DEFAULT, b);

}

}// namespace arms

#endif

void Close();
void far();
void skills();
void nothing();
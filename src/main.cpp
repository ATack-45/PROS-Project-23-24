#include "main.h"
#include "ARMS/config.h"
#include "Region-config.h"



/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	
	pros::lcd::initialize();
	

	pros::lcd::register_btn1_cb(on_center_button);
	arms::init();
	
}

void load() {
    while (true) {
    
    if (stopper.get_value())
		{
			Cata.brake();
			Cata.set_brake_mode(MOTOR_BRAKE_HOLD);
            break;
            
		}
		else {
			Cata.move(100);
		}
    }
}
void fire() {
	Cata.move_relative(400,100);
}
/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
	arms::selector::init;
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	
	arms::odom::reset({0,0},0);
	arms::odom::imu.reset();
	arms::selector::destroy();


	if(arms::selector::auton == 1){
	
		
		
	}

	if(arms::selector::auton == 2){ 
		
	 }

	 

	
	
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	arms::selector::destroy();
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	arms::chassis::setBrakeMode(pros::E_MOTOR_BRAKE_COAST);
	
	cata_track.reset_pos  ();
	
	
	while (true) {
		pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);
		
		arms::chassis::arcade(master.get_analog(ANALOG_LEFT_Y) * (double)100 / 127,
		                      master.get_analog(ANALOG_RIGHT_X) * -(double)100 /127);
							  
		double cata_r = cata_track.get_position();
		

		if (master.get_digital(DIGITAL_L1)) {
			intake.move(-100);
		}
		
		else if (master.get_digital(DIGITAL_R1)){
			intake.move(100);
		}
		
		else {
			intake.move(0);
		
		}

		
		
		if ( cata_track.get_position() > .6 &&  master.get_digital(DIGITAL_R2))
		{
			Cata.move(100);
			intake.move_relative(1000,100);
			pros::delay(100);
			cata_track.reset();
		}
		
		 else if (cata_track.get_position() >=.6)
		{
			Cata.brake();
			Cata.set_brake_mode(MOTOR_BRAKE_HOLD);
			pros::lcd::print(2,"Cata position: %f",cata_r);
			
            
            
		}
		else {
			Cata.move(100);
		}
		

		
		pros::delay(20);
	}
}


#include "main.h"
#include "lemlib/api.hpp"
#include "lemlib/logger/stdout.hpp"
#include "pros/misc.h"
#include "region-config.h"



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
    pros::lcd::initialize(); // initialize brain screen
    chassis.calibrate(); // calibrate sensors
    // cata_track.reset_position(); // uncomment to reset cata position if not working
	


    // the default rate is 50. however, if you need to change the rate, you
    // can do the following.
    // lemlib::bufferedStdout().setRate(...);
    // If you use bluetooth or a wired connection, you will want to have a rate of 10ms

    // for more information on how the formatting for the loggers
    // works, refer to the fmtlib docs

    // thread to for brain screen and position logging
    pros::Task screenTask([&]() {
        lemlib::Pose pose(0, 0, 0);
        while (true) {
            // print robot location to the brain screen
            pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
            pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
            pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
            // log position telemetry
            // delay to save resources
            pros::delay(50);
        }
    });
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

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
    int auto_v; 
	auto_v = floor(auto_select.get_value() /1365);
	pros::lcd::print(2, "Pot auto:%d", auto_v);
	pros::lcd::print(3, "Pot auto:%d", auto_select.get_value());
	
	switch (auto_v)
	{
	case 0: // 1 on wheel
		skills();
		

	case 2: // 2 on wheel
		far();
		break;
	
	case 3: // 3 on wheel
		Close();
		break;
		
	}
/*switch returns value of () and uses appropiate case, more efficent than if, elif because it only checks once */
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

// function for wing deploy
bool wing_state;
	void wing_toggle() {
		if (wing_state) {
			wings.set_value(false);
			pros::delay(5);
			wing_state = false;
		}
		else {
			wings.set_value(true);
			pros::delay(5);
			wing_state = true;
		}
	}
    //adding paths
	ASSET(Debug_txt);
	ASSET(skillsAuto1_txt);

void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);
    //reseting blocka from auto
    blocka.set_value(false);
	
    //setting vars
	bool intake_movef;
	bool intake_moveb;
	bool cata_shoot;
	bool wing_t;
	std::string select_type;
	int CataAngle = cata_track.get_angle();
    cata_track.set_data_rate(5);
	int select_value = floor( drive_select.get_value() / 2048) + 1 ;
	int cata_Pull_Angle = 32291;
	int cata_Move_Angle = cata_Pull_Angle - 00050;
    int leftY;
    int rightY; 

	while (true) {
        /* creating and setting variables*/
        int auto_v; 
        auto_v = floor(auto_select.get_value() /1365);
		int CataAngle = cata_track.get_angle();
        /*screen printing dialouge*/
        
        pros::lcd::print(6, "Cata Angle:%d", CataAngle);
        pros::lcd::print(7, "drive-select:%d", select_value);
		
        


        //auto shoot macro
       if (master.get_digital_new_press(DIGITAL_X)) {
			Cata.move_voltage(11000);
			int count = 35;
			master.rumble("...");
			while (count > 0){
				pros::delay(1000);
				count--;
				master.print(0, 0, "Time: %d", count);
				if (master.get_digital_new_press(DIGITAL_A)){
					count = 0;
				}	
            }
            Cata.move(0);
			master.clear_line(0);
		}

		//odom and PID tuning
		if (master.get_digital_new_press(DIGITAL_A)){
			// chassis.setPose(43.32,-65.542,0);
			// chassis.follow(Debug_txt, 15, 10000);
			// chassis.waitUntilDone();

			// chassis.turnTo(30,0,1000);
            
            chassis.moveToPoint(0,35,10000);
		}

		
                        
        // controller profiles
        switch (select_value)
        {
        case 1:
            // Arcade control scheme
            // get joystick positions
            leftY = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
            rightY = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
            // move the chassis with curvature drive
            chassis.curvature(leftY, rightY);
            select_type = "Alec";

            //button controls 
            if (master.get_digital(DIGITAL_R1)){
                intake_movef = true;
            }
            else if (master.get_digital(DIGITAL_L1))
            {
                intake_moveb = true;
            }
            else {
                intake_movef = false;
                intake_moveb = false;
            }
            if (master.get_digital(DIGITAL_R2)) {
                cata_shoot = true;
            }
            else {
                cata_shoot = false;
            }
            if (master.get_digital_new_press(DIGITAL_L2)) {
                wing_t = true;
            }
            else {
                wing_t = false;
            }
        break;

        case 2:
            // Arcade control scheme
            // get joystick positions
            leftY = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
            rightY = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
            // move the chassis with curvature drive
            chassis.curvature(leftY, rightY);
            select_type = "drew";

            //button controls
            if (master.get_digital(DIGITAL_R1)){
                intake_movef = true;
            }
            else if (master.get_digital(DIGITAL_R2))
            {
                intake_moveb = true;
            }
            else {
                intake_movef = false;
                intake_moveb = false;
            }
            if (master.get_digital(DIGITAL_L1)) {
                cata_shoot = true;
            }
            else {
                cata_shoot = false;
            }
            if (master.get_digital(DIGITAL_L2)) {
                wings.set_value (true);
            }
            else {
                wings.set_value (false);
            }
        break;
        }


        //intake controls
        if (intake_movef) {
            intake.move(-100);
        }
        
        else if (intake_moveb){
            intake.move(100);
        }
        
        else {
            intake.move(0);
        }
        
        //cata controls
        
        if ( 5500 < cata_track.get_position() && (cata_shoot== 1))
        {
            Cata.move_voltage(11000);
            
            pros::delay(5);
        }
        
        else if ( 5500 < cata_track.get_position() )
        {
            Cata.brake();
            Cata.set_brake_mode(MOTOR_BRAKE_HOLD);
            pros::delay(5);
        }
        else
        {
            Cata.move_voltage(11000);
            pros::delay(5);
        }
    
        
        //wings control
        if (wing_t) {
            wing_toggle();
        }
        
        //blocker controls 
        if (master.get_digital(DIGITAL_Y)) {
            blocka.set_value(true);
        }
        else if (master.get_digital(DIGITAL_B)) {
            blocka.set_value(false);
        }
        
        //hang deploy
        if (master.get_digital(DIGITAL_DOWN))
        {
            hang.set_value(true);
        }
        pros::delay(10);
    }  
}
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\lsikora25                                        */
/*    Created:      Thu Sep 08 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    4, 5, 6, 7      
// Controller1          controller                    
// Motor18              motor         18              
// Motor17              motor         17              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
using namespace vex;
competition Competition;
float myVariable;

void drawSmileyAt(int x, int y){
  Brain.Screen.drawCircle(x, y, 40, yellow);
  Brain.Screen.drawCircle(x-20, y-10, 10, blue);
  Brain.Screen.drawCircle(x+20, y-10, 10, blue);
  Brain.Screen.drawRectangle(x-20, y+10, 40, 10, red);
}

//**********************************************************************************************
// "when Controller1 ButtonL1 pressed" hat block
void onevent_Controller1ButtonL1_pressed_0() {
  Motor18.spin(forward);
}

// "when Controller1 ButtonL1 released" hat block
void onevent_Controller1ButtonL1_released_0() {
  Motor18.stop();
}

// "when Controller1 ButtonL2 pressed" hat block
void onevent_Controller1ButtonL2_pressed_0() {
  Motor18.spin(reverse);
}

// "when Controller1 ButtonL2 released" hat block
void onevent_Controller1ButtonL2_released_0() {
  Motor18.stop();
}

//**********************************************************************************************

// "when Controller1 ButtonR1 pressed" hat block
void onevent_Controller1ButtonR1_pressed_0() {
  Motor17.spin(forward);
}

// "when Controller1 ButtonR1 released" hat block
void onevent_Controller1ButtonR1_released_0() {
  Motor17.stop();
}

// "when Controller1 ButtonR2 pressed" hat block
void onevent_Controller1ButtonR2_pressed_0() {
  Motor17.spin(reverse);
}

// "when Controller1 ButtonR2 released" hat block
void onevent_Controller1ButtonR2_released_0() {
  Motor17.stop();
}

//**********************************************************************************************

int onauton_autonomous_0() {
  // anfuiahfiuaehg autonomous
  return 0;
}

//**********************************************************************************************

//AUTONOMOUS SETUP
void VEXcode_auton_task() {
  // Start the auton control tasks....
  vex::task auto0(onauton_autonomous_0);
  while(Competition.isAutonomous() && Competition.isEnabled()) {this_thread::sleep_for(10);}
  auto0.stop();
  return;
}

//DRIVER CONTROLLED
int ondriver_drivercontrol_0() {
  Motor18.setVelocity(9999.0, percent);
  Motor17.setVelocity(9999.0, percent);
  Drivetrain.setDriveVelocity(100.0, percent);
  Drivetrain.setTurnVelocity(70.0, percent);
  return 0;
}

//DRIVER CONTROL SETUP
void VEXcode_driver_task() {
  // Start the driver control tasks....
  vex::task drive0(ondriver_drivercontrol_0);
  
  task rc_auto_loop_task_Controller1();
  while(Competition.isDriverControl() && Competition.isEnabled()) {this_thread::sleep_for(10);}
  drive0.stop();
  return;
}
//**********************************************************************************************

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vex::competition::bStopTasksBetweenModes = false;

  //fun stuff
  Controller1.Screen.print("Pizzahut"); 
  drawSmileyAt(50, 50);
  drawSmileyAt(400, 50);
  drawSmileyAt(50, 200);
  drawSmileyAt(400, 200);

  //setup
  Competition.autonomous(VEXcode_auton_task);
  Competition.drivercontrol(VEXcode_driver_task);
  vexcodeInit();
 
 
 // setting up speeds
  Motor18.setVelocity(9999.0, percent);
  Motor17.setVelocity(9999.0, percent);
  Drivetrain.setDriveVelocity(9999, percent);
  Drivetrain.setTurnVelocity(9999, percent);
  
  //register event handlers
  Controller1.ButtonL1.pressed(onevent_Controller1ButtonL1_pressed_0);
  Controller1.ButtonL1.released(onevent_Controller1ButtonL1_released_0);
  Controller1.ButtonL2.pressed(onevent_Controller1ButtonL2_pressed_0);
  Controller1.ButtonL2.released(onevent_Controller1ButtonL2_released_0);
  
  Controller1.ButtonR1.pressed(onevent_Controller1ButtonR1_pressed_0);
  Controller1.ButtonR1.released(onevent_Controller1ButtonR1_released_0);
  Controller1.ButtonR2.pressed(onevent_Controller1ButtonR2_pressed_0);
  Controller1.ButtonR2.released(onevent_Controller1ButtonR2_released_0);


}

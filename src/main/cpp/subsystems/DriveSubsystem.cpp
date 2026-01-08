// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveSubsystem.h"
#include <iostream>
#include <frc/smartdashboard/SmartDashboard.h>
#include "ctre/Phoenix.h"
#include "ctre/phoenix/motorcontrol/can/TalonSRX.h"


 
//phoenix::motorcontrol::can::TalonFX leftMotor{4};
//phoenix::motorcontrol::can::TalonFX rightMotor{2};
 TalonSRX leftMotor = {3};
 TalonSRX rightMotor = {2};
 double lastValLeft = 0;
 double lastValRight = 0;

DriveSubsystem::DriveSubsystem() {
    leftMotor.ConfigFactoryDefault();
    rightMotor.ConfigFactoryDefault();


    leftMotor.SetInverted(false);
    rightMotor.SetInverted(true);

}


// This method will be called once per scheduler run



 void DriveSubsystem::setspeed(double leftTarget,  double rightTarget){
    

    double leftSpeed = drivePID.Calculate(lastValLeft, leftTarget);
    leftMotor.Set(ControlMode::PercentOutput, leftSpeed);

    double rightSpeed = drivePID.Calculate(lastValRight, rightTarget);
    rightMotor.Set(ControlMode::PercentOutput, rightSpeed);


    frc::SmartDashboard::PutNumber("leftSpeed", leftSpeed);
    frc::SmartDashboard::PutNumber("rightSpeed", rightSpeed);
    
    lastValLeft = leftSpeed;
    lastValLeft = rightSpeed;
} 
void DriveSubsystem::Periodic() {

   
}

void DriveSubsystem::stop(){
    leftMotor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,0);
    rightMotor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,0);
    
}


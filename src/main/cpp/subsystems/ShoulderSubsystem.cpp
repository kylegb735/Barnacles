// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ShoulderSubsystem.h"
#include "frc/DutyCycleEncoder.h"

ShoulderSubsystem::ShoulderSubsystem():
    m_shoulderMotor (4, rev::spark::SparkMax::MotorType::kBrushless),
    m_shoulderEncoder (m_shoulderMotor.GetAbsoluteEncoder())
{   

}

// This method will be called once per scheduler run
void ShoulderSubsystem::Periodic() {}

double ShoulderSubsystem::readEncoder(){
    return m_shoulderEncoder.GetPosition();
}


void ShoulderSubsystem::shoulderManual(double joystick){
    double encoderDegrees = readEncoder();
    frc::SmartDashboard::PutNumber("encoder", encoderDegrees);
    if (encoderDegrees >= 90 && joystick < 0) { // top limit
        m_shoulderMotor.Set(0);
    }
    else if (encoderDegrees <= 10 && joystick > 0) { // bottom limit
        m_shoulderMotor.Set(0);
    }
    else {
        m_shoulderMotor.Set(-joystick*0.15);
    }
}

void ShoulderSubsystem::PickupPosition(){
    double degrees = readEncoder();
    double volt = PickupPID.Calculate(units::degree_t(degrees), units::degree_t(25));
    frc::SmartDashboard::PutNumber("volt calc", volt);
    m_shoulderMotor.SetVoltage(units::volt_t{-volt});
}

void ShoulderSubsystem::ShootPosition(){
    double degrees = readEncoder();
    double volt = ShootPID.Calculate(units::degree_t(degrees), units::degree_t(45));
    frc::SmartDashboard::PutNumber("shoot volt calc", volt);
    m_shoulderMotor.SetVoltage(units::volt_t{volt});
}

void ShoulderSubsystem::HomePosition(){
    double degrees = readEncoder();
    double volt = HomePID.Calculate(units::degree_t(degrees), units::degree_t(105));
    frc::SmartDashboard::PutNumber("volt calc", volt);
    m_shoulderMotor.SetVoltage(units::volt_t{-volt});
}

void ShoulderSubsystem::Stop(){
    m_shoulderMotor.Set(0);
}
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

double ShoulderSubsystem::readEncoder(double encodervalue){
    return m_shoulderEncoder.GetPosition();
    frc::SmartDashboard::PutNumber("arm encoder", m_shoulderEncoder.GetPosition());
}

double ShoulderSubsystem::getShoulderAngle(double encoder){

    double encoderValue = (encoder/(60/22));

    frc::SmartDashboard::PutNumber("fixed encoder", encoder);
    frc::SmartDashboard::PutNumber("e/60/22", encoderValue);
    double offset = 0.7042253521126;
    return offset*360*encoderValue-10;
}


void ShoulderSubsystem::shoulderManual(double joystick){
    double encoderDegrees = getShoulderAngle(m_shoulderEncoder.GetPosition());
    if (encoderDegrees >= 115 && joystick > 0) { // top limit
        m_shoulderMotor.Set(0);
    }
    else if (encoderDegrees <= 65 && joystick < 0) { // bottom limit
        m_shoulderMotor.Set(0);
    }
    else {
        m_shoulderMotor.Set(-joystick*0.15);
    }
}

void ShoulderSubsystem::PickupPosition(){
    double degrees = readEncoder(m_shoulderEncoder.GetPosition());
    double volt = PickupPID.Calculate(units::degree_t(degrees), units::degree_t(11));
    frc::SmartDashboard::PutNumber("volt calc", volt);
    m_shoulderMotor.SetVoltage(units::volt_t{-volt});
}

void ShoulderSubsystem::ShootPosition(){
    double degrees = readEncoder(m_shoulderEncoder.GetPosition());
    double volt = ShootPID.Calculate(units::degree_t(degrees), units::degree_t(74));
    frc::SmartDashboard::PutNumber("shoot volt calc", volt);
    m_shoulderMotor.SetVoltage(units::volt_t{-volt});
}

void ShoulderSubsystem::HomePosition(){
    double degrees = readEncoder(m_shoulderEncoder.GetPosition());
    double volt = HomePID.Calculate(units::degree_t(degrees), units::degree_t(200));
    frc::SmartDashboard::PutNumber("volt calc", volt);
    m_shoulderMotor.SetVoltage(units::volt_t{-volt});
}

void ShoulderSubsystem::Stop(){
    m_shoulderMotor.Set(0);
}
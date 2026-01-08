// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ElbowSubsystem.h"

ElbowSubsystem::ElbowSubsystem() 
  : m_elbowMotor(5, rev::spark::SparkLowLevel::MotorType::kBrushless),
    m_elbowEncoder(m_elbowMotor.GetAbsoluteEncoder())
{
    m_elbowMotor.SetInverted(false);
}

// This method will be called once per scheduler run
void ElbowSubsystem::Periodic() {}

double ElbowSubsystem::readEncoder(double encodervalue){
    return m_elbowEncoder.GetPosition();
    
    frc::SmartDashboard::PutNumber("arm encoder", m_elbowEncoder.GetPosition());
}

double ElbowSubsystem::getArmDegrees(double elbowEncoder){
    double elbowEncoderReading = ((elbowEncoder*(30/0.199))+1.5);
    return elbowEncoderReading;
}

void ElbowSubsystem::elbowManual(double joystick){
    double degree = getArmDegrees(m_elbowEncoder.GetPosition());

    if(degree >= 90 && joystick < 0){ // top limit
        m_elbowMotor.Set(0);
    }
    else if(degree <= 22 && joystick > 0){ // bottom limit
        m_elbowMotor.Set(0);
    }
    else if(joystick != 0) { // normal movement
        double lastPos = degree;
        m_elbowMotor.Set(-joystick*0.15);
    }
    else{ // stationary

        double volt = lockPID.Calculate(degree, lastPos);
        m_elbowMotor.SetVoltage(units::volt_t{volt});
    }

}
void ElbowSubsystem::PickupPosition(){
    double degrees = readEncoder(m_elbowEncoder.GetPosition());
    double volt = PickupPID.Calculate(units::degree_t(degrees), units::degree_t(11));
    frc::SmartDashboard::PutNumber("volt calc", volt);
    m_elbowMotor.SetVoltage(units::volt_t{-volt});
}

void ElbowSubsystem::ShootPosition(){
    double degrees = readEncoder(m_elbowEncoder.GetPosition());
    double volt = ShootPID.Calculate(units::degree_t(degrees), units::degree_t(74));
    frc::SmartDashboard::PutNumber("shoot volt calc", volt);
    m_elbowMotor.SetVoltage(units::volt_t{-volt});
}

void ElbowSubsystem::HomePosition(){
    double degrees = readEncoder(m_elbowEncoder.GetPosition());
    double volt = HomePID.Calculate(units::degree_t(degrees), units::degree_t(200));
    frc::SmartDashboard::PutNumber("volt calc", volt);
    m_elbowMotor.SetVoltage(units::volt_t{-volt});
}

void ElbowSubsystem::Stop(){
    m_elbowMotor.Set(0);
}
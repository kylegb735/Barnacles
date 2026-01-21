// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/controller/PIDController.h>

class DriveSubsystem : public frc2::SubsystemBase {
 public:
  DriveSubsystem();
  void setspeed(double leftSpeed, double rightSpeed);
  void stop();
  void InitDefaultCommand();
  
  frc::PIDController leftDrivePID{
    0.5,0,0
  };
  frc::PIDController rightDrivePID{
    0.5,0,0
  };
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  
};
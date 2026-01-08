// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/SparkMax.h>
#include <frc/DutyCycleEncoder.h>
#include <rev/SparkMaxAlternateEncoder.h>
#include <frc/controller/ProfiledPIDController.h>
#include <frc/controller/PIDController.h>
#include <units/angular_acceleration.h>
#include <units/angular_velocity.h>
#include <frc/smartdashboard/SmartDashboard.h>

class ShoulderSubsystem : public frc2::SubsystemBase {
 public:
  ShoulderSubsystem();
    rev::spark::SparkMax m_shoulderMotor;
    rev::spark::SparkAbsoluteEncoder m_shoulderEncoder;

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
  double readEncoder(double encodervalue);
  double getShoulderAngle(double encoder);
  void shoulderManual(double joystick);
  void PickupPosition();
  void ShootPosition();
  void HomePosition();
  void Stop();

  frc::ProfiledPIDController<units::degrees> PickupPID{
    0.14,0.0135,0,
    frc::TrapezoidProfile<units::degrees>::Constraints{
      units::angular_velocity::degrees_per_second_t(15),
      units::angular_acceleration::degrees_per_second_squared_t(15)
    }
  };
  frc::ProfiledPIDController<units::degrees> ShootPID{
    0.14,0.0135,0,
    frc::TrapezoidProfile<units::degrees>::Constraints{
      units::angular_velocity::degrees_per_second_t(15),
      units::angular_acceleration::degrees_per_second_squared_t(15)
    }
  };
  frc::ProfiledPIDController<units::degrees> HomePID{
    0.14,0.0135,0,
    frc::TrapezoidProfile<units::degrees>::Constraints{
      units::angular_velocity::degrees_per_second_t(15),
      units::angular_acceleration::degrees_per_second_squared_t(15)
    }
  };

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
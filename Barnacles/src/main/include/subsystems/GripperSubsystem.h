// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/Solenoid.h>
#include <frc/Compressor.h>

class Gripper : public frc2::SubsystemBase {
 public:
  Gripper();
  frc::Solenoid m_solenoid{frc::PneumaticsModuleType::CTREPCM, 1};
  frc::Compressor m_compressor{0, frc::PneumaticsModuleType::CTREPCM};

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
  void Grip();
  void Compress();

  bool gripping = false;


 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};

// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc/Joystick.h>

#include "Constants.h"
#include "subsystems/DriveSubsystem.h"
#include "subsystems/ElbowSubsystem.h"
#include "subsystems/ShoulderSubsystem.h"
#include "subsystems/GripperSubsystem.h"

#include <frc2/command/RunCommand.h>


#include <frc/XboxController.h>
#include <frc/controller/PIDController.h>
#include <frc/controller/ProfiledPIDController.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc2/command/Command.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/PIDCommand.h>
#include <frc2/command/ParallelRaceGroup.h>
#include <frc2/command/RunCommand.h>
#include <frc/filter/SlewRateLimiter.h>
#include <frc/Joystick.h>
#include "Constants.h"
#include "frc/DigitalInput.h"
#include "subsystems/DriveSubsystem.h"
#include "subsystems/shoulderSubsystem.h"
#include <subsystems/ElbowSubsystem.h>
#include <commands/GripCommand.h>



/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and trigger mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::CommandPtr GetAutonomousCommand();

 private:
  // Replace with CommandPS4Controller or CommandJoystick if needed
  frc::Joystick m_driverController{0};
  frc::Joystick m_copilotController{1};

  // The robot's subsystems are defined here...
  DriveSubsystem m_drive;
  ElbowSubsystem m_elbow;
  ShoulderSubsystem m_shoulder;
  Gripper m_gripper;

  void ConfigureBindings();
};

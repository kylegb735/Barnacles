// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>
#include <frc2/command/button/JoystickButton.h>


#include <frc/controller/PIDController.h>
#include <frc/geometry/Translation2d.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/trajectory/Trajectory.h>
#include <frc/trajectory/TrajectoryGenerator.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/SwerveControllerCommand.h>
#include <frc2/command/button/JoystickButton.h>
#include <units/angle.h>
#include <units/velocity.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/filter/SlewRateLimiter.h>
#include "Constants.h"
#include "subsystems/DriveSubsystem.h"
#include <frc2/command/InstantCommand.h>
#include <iostream>
#include <frc2/command/SwerveControllerCommand.h>
#include <commands/DriveCommand.h>
#include <commands/ManualShoulderCommand.h>
#include <commands/ShootPositionCommand.h>
#include <commands/PickupPositionCommand.h>
#include <commands/HomePositionCommand.h>
#include <frc2/command/Commands.h>

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureBindings();

    m_gripper.SetDefaultCommand(frc2::RunCommand(
      [this] {
        m_gripper.Compress();    
      },
      {&m_gripper}));
}

void RobotContainer::ConfigureBindings() {
  // Configure your trigger bindings here

  // Schedule `ExampleCommand` when `exampleCondition` changes to `true`
  // frc2::Trigger([this] {
  //   return m_subsystem.ExampleCondition();
  // }).OnTrue(ExampleCommand(&m_subsystem).ToPtr());

  // Schedule `ExampleMethodCommand` when the Xbox controller's B button is
  // pressed, cancelling on release.
  // frc2::JoystickButton()
  m_drive.SetDefaultCommand(DriveCommand(&m_drive, &m_driverController).ToPtr());
  m_shoulder.SetDefaultCommand(ManualShoulderCommand(&m_shoulder, &m_copilotController).ToPtr());
  frc2::JoystickButton(&m_copilotController, 2).OnTrue(ShootPositionCommand(&m_shoulder).ToPtr());
  frc2::JoystickButton(&m_copilotController, 1).OnTrue(PickupPositionCommand(&m_shoulder).ToPtr());
  frc2::JoystickButton(&m_copilotController, 4).OnTrue(HomePositionCommand(&m_shoulder).ToPtr());
  frc2::JoystickButton(&m_copilotController, 3).OnTrue(frc2::cmd::RunOnce([this]{m_gripper.Grip();}));
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  // return autos::ExampleAuto(&m_subsystem);
}

// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ManualShoulderCommand.h"

ManualShoulderCommand::ManualShoulderCommand(ShoulderSubsystem* subsystem, frc::Joystick* joystick) : m_shoulder(subsystem), m_joystick(joystick) {
  AddRequirements(m_shoulder);
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void ManualShoulderCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ManualShoulderCommand::Execute() {
  m_shoulder->shoulderManual(m_joystick->GetRawAxis(5));
}

// Called once the command ends or is interrupted.
void ManualShoulderCommand::End(bool interrupted) {}

// Returns true when the command should end.
bool ManualShoulderCommand::IsFinished() {
  return false;
}

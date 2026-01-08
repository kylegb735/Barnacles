// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/GripCommand.h"

GripCommand::GripCommand(Gripper* Gripper): m_gripper(Gripper) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(Gripper);
}

// Called when the command is initially scheduled.
void GripCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void GripCommand::Execute() {
  m_gripper->Grip();
}

// Called once the command ends or is interrupted.
void GripCommand::End(bool interrupted) {}

// Returns true when the command should end.
bool GripCommand::IsFinished() {
  return false;
}

// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/PickupPositionCommand.h"

PickupPositionCommand::PickupPositionCommand(ShoulderSubsystem* shoulderSubsystem) : m_shoulder(shoulderSubsystem) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(shoulderSubsystem);
}

// Called when the command is initially scheduled.
void PickupPositionCommand::Initialize() {
  m_shoulder->PickupPID.Reset(units::degree_t(m_shoulder->readEncoder()));
  shoulderDone = false; 
}

// Called repeatedly when this Command is scheduled to run
void PickupPositionCommand::Execute() {
  m_shoulder->PickupPosition();

  double shoulderDegree = m_shoulder->readEncoder();
  if(shoulderDegree <= 14 && shoulderDegree >= 12){
    shoulderDone = true;
    Cancel();
  }
}

// Called once the command ends or is interrupted.
void PickupPositionCommand::End(bool interrupted) {}

// Returns true when the command should end.
bool PickupPositionCommand::IsFinished() {
  return false;
}

// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ShootPositionCommand.h"

ShootPositionCommand::ShootPositionCommand(ShoulderSubsystem* shoulderSubsystem) : m_shoulder(shoulderSubsystem) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(shoulderSubsystem);
}

// Called when the command is initially scheduled.
void ShootPositionCommand::Initialize() {
  m_shoulder->ShootPID.Reset(units::degree_t(m_shoulder->readEncoder()));
  shoulderDone = false; 
}

// Called repeatedly when this Command is scheduled to run
void ShootPositionCommand::Execute() {
  m_shoulder->ShootPosition();

  double shoulderDegree = m_shoulder->readEncoder();
  if(shoulderDegree <= 46 && shoulderDegree >= 44){
    shoulderDone = true;
    Cancel();
  }
}

// Called once the command ends or is interrupted.
void ShootPositionCommand::End(bool interrupted) {}

// Returns true when the command should end.
bool ShootPositionCommand::IsFinished() {
  return false;
}

// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ManuelElbowCommand.h"
#include <frc/Joystick.h>

ManualElbowCommand::ManualElbowCommand(ElbowSubsystem* subsystem, frc::Joystick* joystick ): m_elbow(subsystem), m_joystick(joystick) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subsystem);
}

// Called when the command is initially scheduled.
void ManualElbowCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ManualElbowCommand::Execute() {
  m_elbow->elbowManual(m_joystick->GetRawAxis(1));
}

// Called once the command ends or is interrupted.
void ManualElbowCommand::End(bool interrupted) {}

// Returns true when the command should end.
bool ManualElbowCommand::IsFinished() {
  return false;
}

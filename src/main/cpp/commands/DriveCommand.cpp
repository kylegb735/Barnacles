#include "commands/DriveCommand.h"
#include <subsystems/DriveSubsystem.h>
#include <iostream>
#include <frc2/command/Command.h>
#include <frc/Joystick.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <units/angular_velocity.h>
#include <iostream>


DriveSubsystem drive;

DriveCommand::DriveCommand(DriveSubsystem* subsystem, frc::Joystick* joystick) : m_drive(subsystem), m_driverController(joystick) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subsystem);
}

// Called when the command is initially scheduled.
void DriveCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void DriveCommand::Execute() {
  const auto forward = -m_driverController->GetRawAxis(1);
  const auto turn = m_driverController->GetRawAxis(4);


  // if(turn>0){
  //   drive.setspeed(turn, -turn);
  // }

  // if(turn<0){
  //   drive.setspeed(turn, -turn);
  // }


  // //drive.set(left,right);
  // if(forward>0 || forward<0){
  // drive.setspeed(forward,forward);
  // }

  double leftOutput = forward + (turn*.5);
  double rightOutput = forward - (turn*.5);
  double rightLimit;
  double leftLimit;
  if (leftOutput > 1){
    leftOutput = 1;
  }
  else if(rightOutput > 1){
    rightOutput = 1;
  }
  else if (leftOutput < -1){
    leftOutput = -1;
  }
  else if(rightOutput < -1){
    rightOutput = -1;
  }

  if (m_driverController->GetRawButton(5) == true){
     leftLimit = .48;
     rightLimit = .29;
  }
  else{
     leftLimit = 1;
     rightLimit = 0.6;
  }


  drive.setspeed(leftOutput*leftLimit, rightOutput*rightLimit);

  frc::SmartDashboard::PutNumber("forwward axis", forward);
  frc::SmartDashboard::PutNumber("Turning axis", turn);
  frc::SmartDashboard::PutNumber("Left Output", leftOutput);
  frc::SmartDashboard::PutNumber("Right Output", rightOutput);
  frc::SmartDashboard::PutNumber("rightLimit", rightLimit);
  frc::SmartDashboard::PutNumber("leftLimit", leftLimit);
}

// Called once the command ends or is interrupted.
void DriveCommand::End(bool interrupted) {
  drive.stop();
}

// Returns true when the command should end.
bool DriveCommand::IsFinished() {
  return false;
}
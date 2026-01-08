// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>
#include <subsystems/DriveSubsystem.h>
#include <commands/DriveCommand.h>
#include <frc/Joystick.h>

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending Command
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
// class DriveCommand

class DriveCommand : public frc2::CommandHelper<frc2::Command, DriveCommand> {
private:
    DriveSubsystem* m_drive; frc::Joystick* m_driverController;
    
public:
    DriveCommand(DriveSubsystem* m_driveSubsystem , frc::Joystick* m_joystick); // Constructor declaration
    void Initialize() override;
    void Execute() override;
    void End(bool interrupted) override;
    bool IsFinished() override;
};
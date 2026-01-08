// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/GripperSubsystem.h"
#include <frc/smartdashboard/SmartDashboard.h>

Gripper::Gripper() = default;

// This method will be called once per scheduler run
void Gripper::Periodic() {}


void Gripper::Grip() {
    gripping = !gripping;

    if (gripping){
        m_solenoid.Set(true); // close
    }
    else {
        m_solenoid.Set(false); // open
    }
}

void Gripper::Compress(){
    bool pressureSwitch = m_compressor.GetPressureSwitchValue();
    bool compressorEnabled = m_compressor.IsEnabled();

    if (!pressureSwitch) {
        m_compressor.EnableDigital();
    }

    // frc::SmartDashboard::PutBoolean("pressure switch", pressureSwitch);
}
# Automated Availability Signaling System for Customer Service

This project, part of the Integrated Project course, aims to create a system that identifies available service desks at the DEI Secretaria without being intrusive. The system automates the monitoring and display of desk availability.

## Problem

Current methods of checking desk availability are either manual or intrusive, disrupting the workflow at the secretariat.

## Solution

The solution uses sensors to detect the presence of staff at service desks. This data is processed and displayed through a user-friendly interface, allowing students and visitors to see desk availability without disturbing staff.

### System Components
- **Distance Sensor:** Detects presence or movement near the desk.
- **Microcontroller:** Processes sensor data and communicates with the MQTT broker.
- **Router:** Connects the microcontroller to the MQTT broker.
- **Microcomputer:** Sends data to the display system.
- **Display System:** Shows desk availability through a graphical interface.

## Requirements

- **Sensors:** Detect presence at service desks.
- **MQTT Broker:** Manages communication between components.
- **Microcontroller:** Handles sensor data and updates the system.
- **Router/Microcomputer:** Manage data transmission.
- **GUI:** Displays desk availability in real-time.

## Steps

1. **Deploy Sensors:** Install sensors at each desk.
2. **Process Data:** Determine if desks are occupied.
3. **Communicate:** Microcontroller sends data to the MQTT broker.
4. **Implement GUI:** Display availability in real-time.
5. **Test:** Ensure accurate detection and display.

# 🤖 EfenSys - Smart Robotic Arm System

## Overview

EfenSys is an IoT-enabled robotic arm solution designed to increase flexibility and efficiency in manufacturing industries. Traditional robotic arms often require repetitive hardcoding whenever a new task is introduced, resulting in increased production costs, downtime, and dependence on specialized personnel.

EfenSys solves this problem by providing a cloud-connected graphical user interface (GUI) that allows authorized users to easily configure and control robotic arm movements without modifying firmware or writing new code.

---

## Problem Statement

Manufacturing industries face several challenges with conventional robotic systems:

* Repetitive hardcoding for every new task.
* Increased production and maintenance costs.
* Limited robot adaptability.
* Requirement of specialized programming knowledge.
* Reduced productivity due to downtime during reconfiguration.

---

## Solution

EfenSys introduces a smart robotic control platform that enables users to:

* Configure robotic movements through a user-friendly application.
* Send commands remotely via the Internet.
* Store and manage instructions using Firebase Cloud.
* Reconfigure robots for new tasks without firmware modification.
* Improve production efficiency and operational flexibility.

---

## Features

* 🌐 IoT-based robotic control
* 📱 Graphical User Interface (GUI)
* ☁️ Firebase cloud communication
* 🔄 Real-time robot reconfiguration
* 🏭 Manufacturing automation
* 📡 Wi-Fi connectivity
* 🦾 Multi-servo robotic arm control
* ⚡ Reduced setup and programming time

---

## System Architecture

```text
Application
     │
     ▼
Firebase Database
     │
     ▼
 JRC Board (ESP32)
     │
     ▼
 Robotic Arm Servos
```

---

## Hardware Components

| Component         | Description                              |
| ----------------- | ---------------------------------------- |
| JRC Board (ESP32) | Main controller with Wi-Fi and Bluetooth |
| Servo Motors      | Robotic arm movement control             |
| Buck Converter    | Voltage regulation (12V to 5V)           |
| 12V SMPS          | Power supply for the complete system     |

---

## Software Stack

* Arduino IDE
* Google Firebase Realtime Database
* ESP32 Framework
* Custom GUI Application

---

## Working Principle

1. User configures robotic movements using the GUI application.
2. Commands are uploaded to Firebase Database.
3. JRC Board receives instructions through Wi-Fi.
4. The controller processes commands.
5. Servo motors execute the specified movement.
6. Users can instantly reconfigure the robot for new tasks.

---

## Technical Specifications

| Specification      | Value             |
| ------------------ | ----------------- |
| Controller         | ESP32 (JRC Board) |
| CPU                | 32-bit            |
| RAM                | 520 KB            |
| Input Voltage      | 12V               |
| Degrees of Freedom | 5 DOF             |
| Maximum Reach      | 25 cm             |
| Maximum Payload    | 1.6 kg            |

---

## Applications

* Manufacturing Automation
* Pick-and-Place Operations
* Assembly Lines
* Educational Robotics
* Industrial Research
* Smart Factory Systems

---

## Future Improvements

* Digital Twin Technology
* AI-based Motion Optimization
* Advanced Path Planning
* Remote Monitoring Dashboard
* Industrial-scale Deployment
* Predictive Maintenance System

---

## Dependencies

* Stable Internet Connection
* Reliable Power Supply
* Firebase Backend Service

---

## Team

### The Hack Clowns

* Israfil Shaheen Arannya
* Atiqur Rahman
* Mir Muhammad Abidul Haq Ahnaf

---

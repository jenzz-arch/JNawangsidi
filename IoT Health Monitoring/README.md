# IoT Health Monitoring System

An Internet of Things (IoT)-based health monitoring system that measures heart rate in real time using a Pulse Sensor and Arduino Uno. The collected data is transmitted via an ESP8266 Wi-Fi module to the Blynk IoT platform, enabling users to monitor their heart rate remotely through a mobile application.

<p align="center">
  <img src="IoT Heart Monitoring Image.png" alt="IoT Health Monitoring System" width="650"/>
</p>

---

## Overview

This project demonstrates the integration of embedded systems and IoT technologies for real-time health monitoring. A Pulse Sensor continuously measures the user's heart rate, while an Arduino Uno processes the sensor data and calculates the heart rate in beats per minute (BPM). The ESP8266 Wi-Fi module then transmits the data to the Blynk IoT platform, allowing users to monitor their heart rate remotely through a smartphone.

The system also detects abnormal heart rate readings, making it a simple and effective demonstration of remote health monitoring using embedded systems and wireless communication.

---

## Features

- Real-time heart rate monitoring
- Remote monitoring through the Blynk mobile application
- Live heart rate (BPM) visualization
- Wireless data transmission via ESP8266
- Abnormal heart rate detection

---

## Hardware Components

- Arduino Uno
- Pulse Sensor
- ESP8266 Wi-Fi Module
- Breadboard
- Jumper Wires
- USB Cable

---

## Software

- Arduino IDE
- Blynk IoT Platform

---

## System Workflow

1. The Pulse Sensor continuously measures the user's heart rate.
2. The Arduino Uno processes the sensor signal and calculates the heart rate in beats per minute (BPM).
3. The ESP8266 Wi-Fi module sends the heart rate data to the Blynk IoT platform over Wi-Fi.
4. Users can view their heart rate in real time through the Blynk mobile application.

---

## Wiring Diagram

<p align="center">
  <img src="Wiring IoT Health Monitoring.png" alt="Wiring Diagram" width="700"/>
</p>

---

## Project Demonstration

<p align="center">
  <img src="IoT Heart Monitoring Image.png" alt="Project Demonstration" width="700"/>
</p>

---

## Project Structure

```text
IoT Health Monitoring/
├── heart_monitoring_sukses.ino
├── IoT Heart Monitoring Image.png
├── Wiring IoT Health Monitoring.png
├── Full Paper_Tim Anugerah_INJECTION_EPW 15.pdf
└── README.md
```

---

## Future Improvements

- Integrate additional health sensors, such as SpO₂ and body temperature sensors.
- Store historical health data in a cloud database.
- Develop a web-based monitoring dashboard.
- Implement AI-based health anomaly detection.
- Add automatic notifications for abnormal heart rate readings.

---

## Documentation

The complete project report is available in this repository:

- **Full Paper_Tim Anugerah_INJECTION_EPW 15.pdf**

---

## Author

**Jendra Nawangsidi**

High school student passionate about Artificial Intelligence, Internet of Things (IoT), Robotics, and Data Engineering.

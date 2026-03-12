# 🐟 PECERAPP – IoT Aquarium Monitoring System

PECERAPP is an **IoT platform designed to monitor and manage aquarium conditions remotely**.  
The project was developed as a **final project for an Internet of Things course**, focusing on real-time monitoring, automation, and cloud data visualization.

Aquaculture currently produces **more than 50% of aquatic products consumed worldwide**, but it faces several challenges such as:

- Inadequate or fluctuating water conditions  
- Lack of efficient real-time monitoring tools  

PECERAPP aims to solve these problems by integrating **sensors, automation, and cloud monitoring**.

---

# Project Objective

Guarantee **optimal environmental conditions for aquatic flora and fauna** through:

- Real-time monitoring  
- Automated water management  
- Cloud visualization and alerts

---

# How PECERAPP Works

The system continuously monitors aquarium parameters and reacts automatically when values fall outside safe limits.

Main functionalities:

- 📊 **Real-time monitoring** of aquarium conditions  
- ☁️ **Cloud data visualization** using Ubidots  
- 🚨 **Automatic alerts** when abnormal conditions are detected  
- 🔄 **Automatic water refill system** using a servo-controlled pump  

When the water level drops below the defined threshold:

1. The sensor detects the change  
2. The system sends data to the server/cloud  
3. The actuator activates the **MG995 servo motor**
4. The pump refills the aquarium automatically

---

# System Architecture

## Hardware

- **DS18B20** – Water temperature sensor  
- **HC-SR04** – Ultrasonic sensor for water level  
- **MG995 Servo Motor** – Controls water refill mechanism  
- **Arduino Microcontroller** – Handles sensor readings and actuator control  

---

## Software

- **Node.js + Express** – Backend server  
- **SQLite** – Local database storage  
- **MQTT** – Communication with IoT devices  
- **Ubidots Cloud Platform** – Data visualization and analytics  
- **Web Interface** – Real-time monitoring dashboard

---

# Dependencies

Main backend dependencies used in the project:

- express  
- axios  
- cors  
- body-parser  
- mqtt  
- sqlite3  

These are defined in `package.json`.

---

# Installation

### Clone the repository

```bash
git clone https://github.com/rosinaflrz/projectpecerapp.git
```

### Go to the project directory

```bash
cd projectpecerapp
```

### Install dependencies

```bash
npm install
```

### Start the server

```bash
npm start
```

The backend will start running using:

```bash
node server.js
```

---

# IoT Communication Flow

1️⃣ Sensors collect aquarium data  
2️⃣ Arduino sends data via MQTT or HTTP  
3️⃣ Node.js backend processes the data  
4️⃣ Data is stored locally (SQLite)  
5️⃣ Data is sent to **Ubidots Cloud**  
6️⃣ Users monitor aquarium conditions through the web interface  

---

# Future Improvements

Potential improvements for the project:

- Mobile application for monitoring  
- Machine learning for anomaly detection  
- Automatic feeding system  
- More sensors (pH, dissolved oxygen, turbidity)  
- Push notifications

---

# 🎓 Academic Project

This project was developed as part of an **Internet of Things (IoT) course**, combining embedded systems, cloud platforms, and web technologies.

# Enhanced Waste Collection using IoT Technology: A Smart Waste Collection System for Efficient Campus Operations

This project proposes a smart and sustainable solution to address pollution caused by solid waste on college campuses. By integrating Internet of Things (IoT) technology, the system enhances the efficiency of waste collection processes, promoting a cleaner and safer campus environment.

A custom-designed IoT device is mounted inside waste bins to monitor real-time fill levels. Once a bin crosses a predefined threshold, the system automatically triggers SMS alerts to the designated waste collection personnel, enabling timely and optimized garbage collection.

To further ensure safety, the device is equipped with IR flame sensors and MQ-6 gas sensor to detect potential fire hazards and the leakage of harmful gases from accumulated waste. This feature adds a critical layer of hazard prevention and response.

The real-time data collected is vital for data-driven decision-making in campus waste management. It aids in identifying high-traffic areas requiring additional bins and allocating waste management resources more effectively.

Ultimately, this system minimizes the environmental footprint of solid waste, ensures a hygienic and secure campus, and supports the overall well-being of students and faculty—making it a crucial component of an effective educational infrastructure.

## 🚀 Features

- 📦 **Real-time bin monitoring** using ultrasonic sensors
- 📩 **Automated SMS alerts** to waste collectors when bins are full
- 🔥 **IR flame detection** for early fire warnings
- ☠️ **Gas sensors** to detect harmful gas leakage
- 📊 **Data analytics** for smarter resource allocation and planning

---

## 🛠️ Technologies Used

- **Microcontroller**: Arduino Uno / ESP32
- **Sensors**:
  - Ultrasonic sensor (for bin fill level)
  - IR Flame sensor
  - Gas sensor (e.g., MQ-2)
- **Communication**: GSM module for SMS alerts
- **Platform**: Embedded C / Arduino IDE
- **Data Handling**: Serial monitor (expandable to cloud)

---

## ⚙️ How It Works

1. IoT sensors detect the fill level inside the bin.
2. When the threshold is reached, an SMS is sent to the waste collection team.
3. Flame and gas sensors monitor safety conditions in real-time.
4. Data collected helps campus management optimize bin placement and staff deployment.

---

## 🧰 Installation & Setup

> **Note**: This guide assumes you're using an Arduino board.

1. Connect the ultrasonic, gas, and flame sensors to the microcontroller.
2. Connect the GSM module for SMS capabilities.
3. Upload the code to your board using the Arduino IDE.
4. Power the device and monitor the serial output for live data.

---


## 📄 License

This project is licensed under the [MIT License](LICENSE).

---

## 👨‍💻 Authors

- Vaishnav P Nambiar  
- N. Mohammed Ashraf

---

## 📬 Contact

For questions or collaborations, reach out via connect on LinkedIn (https://www.linkedin.com/in/vaishnav-p-nambiar).


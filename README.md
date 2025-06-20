# Arduino-Rain-Sensor-with-OLED-Display
This project uses an **Arduino**, a **rain sensor**, and a **0.96" I2C OLED screen** (SSD1306) to detect rainfall and display the status in real time. It's a simple, educational, and practical setup for weather monitoring.

---

## Components Required

- Arduino Uno/Nano
- Rain sensor module (digital output)
- SSD1306 OLED display (128x64 I2C)
- Jumper wires
- Breadboard (optional)

---

## Libraries Used

Install the following libraries via the Arduino Library Manager:

- [`Adafruit_GFX`](https://github.com/adafruit/Adafruit-GFX-Library)
- [`Adafruit_SSD1306`](https://github.com/adafruit/Adafruit_SSD1306)
- `Wire.h` (comes built-in with Arduino IDE)

---

## 🔧 Circuit Diagram

| Pin            | Connection          |
|----------------|---------------------|
| Rain Sensor    | Digital Pin 2 (D2)  |
| OLED VCC       | 5V                  |
| OLED GND       | GND                 |
| OLED SDA       | A4 (Uno/Nano)       |
| OLED SCL       | A5 (Uno/Nano)       |

>  Note: For ESP32/ESP8266, SDA/SCL pins differ.

---

## How It Works

- Reads the **digital signal** from the rain sensor.
- Displays a message on the **OLED screen**:
  - `"Raining!"` if rain is detected.
  - `"No Rain..."` otherwise.
- Sends the same message over **Serial Monitor** (baud rate 9600).

---

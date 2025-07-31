> ⚠️ **WARNING**  
> This project has **not been tested on real hardware yet**.  
> The PCB has been designed, and the firmware is complete, but it hasn't been uploaded or verified on a physical board yet.  


# BinaryCounter
A simple hardware built using KiCad and C++ (Arduino code), designed to work as a counter with keys, 0.96" OLED screen, LEDs all controlled by a XIAO-RP2040-DIP microcontroller.


## Features

- **Counter Functionality:** with Increment, Decrement, Reset, and Display mode controls.  
- **4 LEDs:** for displaying the count in binary (upto 15).
- **OLED Display (128x64):** for displaying count in decimal.  
- **Four Mechanical Buttons:** for control.
---
## Screenshots

**Schematics**
![Schematics](<Images/Schematic.png>)

**PCB**
![PCB](<Images/PCB.png>)

**3D Front View**
![3D-Front](<Images/3DFront.png>)

**3D Back View**
![3D-Back](<Images/3DBack.png>)
---

## How It Works

- **Button 1 (GPIO26)** → Increase Count
- **Button 2 (GPIO27)** → Decrease Count
- **Button 3 (GPIO28)** → Reset Count (back to 0)
- **Button 4 (GPIO29)** → Toggle light or dark mode
- **OLED (I2C: GPIO6, GPIO7)** → Visual feedback  
- **LEDs (GPIO1 - GBIO4)** → Binary feedback (last 4 digits)

---

## Pin Mapping

| Component           | Function           | Pin on XIAO RP2040  |
|---------------------|--------------------|---------------------|
| Button 1            | Increase           | GPIO026             |
| Button 2            | Decrease           | GPIO27              |
| Button 3            | Reset              | GPIO28              |
| Button 4            | Toggle Display     | GPIO29              |
| OLED SDA            | I2C SDA            | GPIO6               |
| OLED SCL            | I2C SCL            | GPIO7               |
| LED 1               | 2^3 (eights place) | GPIO1               |
| LED 2               | 2^2 (fours place)  | GPIO2               |
| LED 3               | 2^1 (twos place)   | GPIO4               |
| LED 4               | 2^0 (units place)  | GPIO3               |

---

## Firmware

The firmware has been written with Arduino IDE using C++.

**Libraries used:**
- `Wire.h`: I2C communication
- `Adafruit_GFX.h`: OLED graphics
- `Adafruit_SSD1306.h`: OLED driver

---

## PCB Design

The PCB is designed using KiCad.
- All symbols are from KiCad or open-source, you can find the custom ones in the "Resources" folder.
---

## Firmware
- This Firmware and program is for demo purposes.
- I am working on my main idea and on many firmwares for this device so stay tuned.

## Acknowledgement
Made for [Pathfinder](https://pathfinder.hackclub.com/) hosted by Hackclub.

## License
[MIT License](LICENSE).  
---

## Author
[GlassyBridge](https://github.com/GlassyBridge)

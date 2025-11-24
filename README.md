# Focus Lamp Firmware

An ESP32-based IoT smart desk lamp featuring:
- Pomodoro timer functionality (25-min focus, 5-min breaks)
- Auto-brightness control with BH1750 light sensor
- Blynk integration for remote task management
- 3.5" TFT touchscreen display
- Rotary encoder for manual control

## Hardware Requirements
- ESP32-WROOM-32 Dev Module
- 3.5" TFT Touchscreen (ILI9488, 8-bit Parallel)
- BH1750 light sensor
- Rotary encoder
- MOSFET for LED control
- Buzzer

## Pin Configuration

| Component | Pin |
|-----------|-----|
| **Display CS** | 33 |
| **Display DC** | 15 |
| **Display RST** | 32 |
| **Display WR** | 4 |
| **Display RD** | 2 |
| **Display D0-D7** | 12, 13, 26, 25, 17, 16, 27, 14 |
| **Encoder CLK** | 35 |
| **Encoder DT** | 34 |
| **Encoder SW** | 36 |
| **Light Sensor SDA** | 21 |
| **Light Sensor SCL** | 22 |
| **LED MOSFET** | 18 |
| **Buzzer** | 5 |

# Focus Lamp Firmware

An ESP32-based IoT smart desk lamp featuring:
- Pomodoro timer functionality (25-min focus, 5-min breaks)
- Auto-brightness control with BH1750 light sensor
- Blynk integration for remote task management
- 3.5" TFT touchscreen display
- Rotary encoder for manual control

## Hardware Requirements
- ESP32-WROOM-32 Dev Module
- 3.5" TFT Touchscreen (ILI9488, 8-bit Parallel)
- BH1750 light sensor
- Rotary encoder
- MOSFET for LED control
- Buzzer

## Pin Configuration

| Component | Pin |
|-----------|-----|
| **Display CS** | 33 |
| **Display DC** | 15 |
| **Display RST** | 32 |
| **Display WR** | 4 |
| **Display RD** | 2 |
| **Display D0-D7** | 12, 13, 26, 25, 17, 16, 27, 14 |
| **Encoder CLK** | 35 |
| **Encoder DT** | 34 |
| **Encoder SW** | 36 |
| **Light Sensor SDA** | 21 |
| **Light Sensor SCL** | 22 |
| **LED MOSFET** | 18 |
| **Buzzer** | 5 |

## Setup
1. Install PlatformIO in VS Code
2. Clone this repository
3. Update credentials in `include/config.h`
4. Build and upload to ESP32

## Features
- Automatic brightness adjustment based on ambient light
- Manual brightness control via rotary encoder
- Blynk-synced to-do list
- Visual and audible timer alerts
- TFT display showing timer, tasks, and brightness levels

# PlatformIO
.pio/
.piolibdeps/
.vscode/
*.pyc
__pycache__/

# OS generated files
.DS_Store
Thumbs.db
ehthumbs.db
Icon?
apidoc/
.coverage

# Temporary files
*.tmp
*.temp
tmp/
temp/

# Debug
debug/
Debug/
build/
Build/

# Arduino IDE
*.o
*.a
*.so
*.d
*.eep
*.hex
*.lss
*.lst
*.map
*.sym
*.bin
*.zip

# Build artifacts
.platformio/

MIT License

Copyright (c) 2025 [Your Name]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.


## Setup
1. Install PlatformIO in VS Code
2. Clone this repository
3. Update credentials in `include/config.h`
4. Build and upload to ESP32

## Features
- Automatic brightness adjustment based on ambient light
- Manual brightness control via rotary encoder
- Blynk-synced to-do list
- Visual and audible timer alerts
- TFT display showing timer, tasks, and brightness levels

# PlatformIO
.pio/
.piolibdeps/
.vscode/
*.pyc
__pycache__/

# OS generated files
.DS_Store
Thumbs.db
ehthumbs.db
Icon?
apidoc/
.coverage

# Temporary files
*.tmp
*.temp
tmp/
temp/

# Debug
debug/
Debug/
build/
Build/

# Arduino IDE
*.o
*.a
*.so
*.d
*.eep
*.hex
*.lss
*.lst
*.map
*.sym
*.bin
*.zip

# Build artifacts
.platformio/

MIT License

Copyright (c) 2025 [Your Name]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

# Claude summary (Too lazy to write this one, i wrote everything else):
  Show more12:30 PMThis is Arduino/ESP32 code for an automated waste bin and water pump system. Here's what it does:
  Hardware it controls

  3 IR distance sensors (to detect fill levels in a bin)
  1 water level switch sensor
  1 water pump (via relay)
  1 servo motor (a flap/door)
  1 16x2 LCD display

  How it works
  Every loop cycle, it reads all sensors and makes a decision:
  Normal operation (runSystem) — if the bin isn't full and water isn't too high:

  Turns the pump ON
  Opens the flap/door to 90°
  LCD shows "System Running" and the status of each layer (F = Full, O = Open/empty)

  Bin Full — if all 3 IR sensors detect something close (≥2100mV):

  Turns pump OFF
  Closes flap to 0°
  LCD shows "Bin Full!"

  Water High — if the float/switch sensor trips:

  Turns pump OFF
  Closes flap to 0°
  LCD shows "Water High!"

  The bigger picture
  This looks like a smart composting or waste sorting bin — the 3 IR sensors measure fill level at 3 different heights (layers), the servo controls a gate/flap, and the pump likely handles liquid drainage or moisture. The system automatically stops everything when the bin is full or water overflows.

# Installing software
  use arduino IDE v2 and install the esp32 from espressifSystems in board manager.
  https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/

  then install the following libraries in library manager:
  esp32servo by kevin harrington and john k bennet
  liquidcrystali2c by frank de brabander 

# Components

## Sharp IR Sensor:
  https://www.instructables.com/How-to-Use-the-Sharp-IR-Sensor-GP2Y0A41SK0F-Arduin/ (if using library)
  https://global.sharp/products/device/lineup/data/pdf/datasheet/gp2y0a41sk_e.pdf (without library)
  https://randomnerdtutorials.com/esp32-adc-analog-read-arduino-ide/ (without library)
  either use the voltage to distance graph for the method without the library or
  use the library (unreliable readings due to using analogRead which is unreliable for ESP32)

## Water Switch:
  Connect one end of the switch to GND and the other to the input pin set in the 
  code. It acts like a button where when the water reaches the desired point, the
  circuit closes and thus will be detected by the board

## Pump:
  Connect the pump relay pin to a relay and the pump should be connected to the relay. 
  The relay should allow 3.3V, connect battery positive to com and pump positive in NO.

## Servo:
  docs:
  https://esp32io.com/tutorials/esp32-mg996r 

## I2C lcd:
  https://randomnerdtutorials.com/esp32-esp8266-i2c-lcd-arduino-ide/

servo and i2c should be the simplest since theyre just PWM or I2C and have libraries

# Connection Docs

## Sharp IR sensors: 
  connect the three sensors into GPIO pins 34, 32, 33, whereas 34
  is for level 1, 32 is for level 2, 33 is for level 3. Connect the ground pin to the common ground for 5V components.

## Water Switch:
  connect one end to the common ground and the other end to GPIO 27.

## Pump:
  The pump is to be powered via the relay. Connect the COM to the 12V battery's 
  positiive terminal and connect the GND pin of the Pump to the battery's negative terminal. then, connect the relay's NO (normally open) to the pump's positive terminal.

  Connect GPIO 25 to the relay's input, conect the relay's VCC to the 5V terminal from the buck in parallel, and connect the relay's GND to the common ground.

## Servo:
  Connect VCC to 5V terminal from buck in parallel, GND to common ground and
  Input to GPIO 26

## LCD:
  connect GPIO 21 to SDA, GPIO 22 to SCL, VCC to 5v output of the buck in parallel,
  and GND to common ground.

## Battery and DC-DC Buck:
  Connect the battery's positive terminal to IN+ and the negative terminal to
  IN-. the Buck's OUT+ and OUT- will be used for the 5V components.

## ESP32:
  Connect the 5V or Vin pin in the esp32 into the buck's OUT+ and GND to OUT-.

# Debugging / Issues

  Test out i2c lcd first by using an i2c detector code
  https://randomnerdtutorials.com/esp32-i2c-scanner-arduino/

  The IR sensor will not detect when object is too close 2-1cm

  for the servo, it's best to create a seperate script to set see
  what the 0 and 90 angle positions are.
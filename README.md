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
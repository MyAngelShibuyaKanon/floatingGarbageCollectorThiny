# Sharp IR Sensor:
  https://www.instructables.com/How-to-Use-the-Sharp-IR-Sensor-GP2Y0A41SK0F-Arduin/ (if using library)
  https://global.sharp/products/device/lineup/data/pdf/datasheet/gp2y0a41sk_e.pdf (without library)
  https://randomnerdtutorials.com/esp32-adc-analog-read-arduino-ide/ (without library)
  either use the voltage to distance graph for the method without the library or
  use the library (unreliable readings due to using analogRead which is unreliable for ESP32)

# Water Switch:
  Connect one end of the switch to GND and the other to the input pin set in the 
  code. It acts like a button where when the water reaches the desired point, the
  circuit closes and thus will be detected by the board

# Pump:
  Connect the pump relay pin to a relay and the pump should be connected to the relay. 
  The relay should allow 3.3V, connect battery positive to com and pump positive in NO.

# Servo:
  docs:
  https://esp32io.com/tutorials/esp32-mg996r 

# I2C lcd:
  https://randomnerdtutorials.com/esp32-esp8266-i2c-lcd-arduino-ide/

servo and i2c should be the simplest since theyre just PWM or I2C and have libraries

  

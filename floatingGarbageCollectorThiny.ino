#include <ESP32Servo.h>
#include <LiquidCrystal_I2C.h>

// Set IR consts
#define MIN_DISTANCE_VOLT 2100 // 2100 millivolt, check sensor distance to volt graph to adjust
//GPIO Pins, check diagram, ADC pins
#define IR_PIN1 32
#define IR_PIN2 33
#define IR_PIN3 34

// water level sensor switch
# define WATER_SWITCH_PIN 27

// water pump and servo pins (Digital to Analog pins)
#define PUMP_RELAY_PIN 25
#define SERVO_PIN 26

// Initialize servo and lcd objects
Servo flapServo;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  // initialize pin modes
  pinMode(WATER_SWITCH_PIN, INPUT_PULLUP);
  pinMode(PUMP_RELAY_PIN, OUTPUT);

  // attach servo
  flapServo.attach(SERVO_PIN);
  
  // initialize lcd
  lcd.init();
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  // get voltage readings on IR sensors
  int dist1 = analogReadMilliVolts(IR_PIN1);
  int dist2 = analogReadMilliVolts(IR_PIN2);
  int dist3 = analogReadMilliVolts(IR_PIN3);

  // check if water switch active, if so, it means the water level is high
  bool waterHigh = !digitalRead(WATER_SWITCH_PIN);

  // combined boolean logic for 3 IR sensor
  bool isBinFull = dist1 <= MIN_DISTANCE_VOLT && dist2 <= MIN_DISTANCE_VOLT && dist3 <= MIN_DISTANCE_VOLT;

  if (isBinFull) {
    stopSystem("Bin Full!");
  } else if (waterHigh){
    stopSystem("Water High!");
  }else {
    runSystem();
  }
}

void runSystem() {
  digitalWrite(PUMP_RELAY_PIN, HIGH);
  flapServo.write(90); // Open Flap
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("System: ACTIVE ");
}

void stopSystem(const char* message) {
  digitalWrite(PUMP_RELAY_PIN, LOW);
  flapServo.write(0); // Close Flap
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(message);
}
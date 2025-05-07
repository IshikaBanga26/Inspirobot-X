#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <DHT.h>

// Define Motor Pins
#define ENA 9
#define IN1 8
#define IN2 7
#define IN3 6
#define IN4 5
#define ENB 4

// Define Sensors
#define IR_SENSOR A0
#define ULTRASONIC_TRIG 10
#define ULTRASONIC_ECHO 11
#define PH_SENSOR A1
#define TURBIDITY_SENSOR A2
#define DHT_SENSOR 2
#define MQ135_SENSOR A3
#define WATER_TEMP_SENSOR A4
#define COLOR_SENSOR_S0 3
#define COLOR_SENSOR_S1 4
#define COLOR_SENSOR_S2 5
#define COLOR_SENSOR_S3 6
#define COLOR_SENSOR_OUT 7

// Modules
DHT dht(DHT_SENSOR, DHT11);
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo sampleServo;

void setup() {
    Serial.begin(9600);
    pinMode(ENA, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(ENB, OUTPUT);

    pinMode(IR_SENSOR, INPUT);
    pinMode(ULTRASONIC_TRIG, OUTPUT);
    pinMode(ULTRASONIC_ECHO, INPUT);
    pinMode(PH_SENSOR, INPUT);
    pinMode(TURBIDITY_SENSOR, INPUT);
    pinMode(MQ135_SENSOR, INPUT);
    pinMode(WATER_TEMP_SENSOR, INPUT);

    dht.begin();
    lcd.begin();
    lcd.backlight();
    sampleServo.attach(9);
}

void loop() {
    int irValue = analogRead(IR_SENSOR);
    int phValue = analogRead(PH_SENSOR);
    int turbidityValue = analogRead(TURBIDITY_SENSOR);
    int airQuality = analogRead(MQ135_SENSOR);
    int waterTemp = analogRead(WATER_TEMP_SENSOR);
    
    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();
    
    int distance = getUltrasonicDistance();

    lcd.setCursor(0, 0);
    lcd.print("Air: ");
    lcd.print(airQuality);
    lcd.print(" PPM");

    lcd.setCursor(0, 1);
    lcd.print("Water pH: ");
    lcd.print(phValue);

    Serial.print("Air Quality: ");
    Serial.println(airQuality);
    Serial.print("pH Value: ");
    Serial.println(phValue);
    Serial.print("Turbidity: ");
    Serial.println(turbidityValue);
    Serial.print("Water Temp: ");
    Serial.println(waterTemp);
    Serial.print("Humidity: ");
    Serial.println(humidity);
    Serial.print("Temperature: ");
    Serial.println(temperature);
    Serial.print("Distance: ");
    Serial.println(distance);

    if (distance < 10) {
        stopRobot();
        delay(500);
        moveBackward();
        delay(1000);
        stopRobot();
    } else {
        moveForward();
    }

    delay(1000);
}

int getUltrasonicDistance() {
    digitalWrite(ULTRASONIC_TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(ULTRASONIC_TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(ULTRASONIC_TRIG, LOW);

    long duration = pulseIn(ULTRASONIC_ECHO, HIGH);
    int distance = duration * 0.034 / 2;
    return distance;
}

void moveForward() {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, 150);
    analogWrite(ENB, 150);
}

void moveBackward() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENA, 150);
    analogWrite(ENB, 150);
}

void stopRobot() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}
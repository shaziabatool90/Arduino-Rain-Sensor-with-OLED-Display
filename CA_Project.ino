#include <Wire.h> //for I2C 
#include <Adafruit_GFX.h> //for text display
#include <Adafruit_SSD1306.h> //for OLED

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64

#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int rainSensorPin = 2;  // Digital pin for rain sensor

void setup() {
  pinMode(rainSensorPin, INPUT);
  Serial.begin(9600);

  // Initialize OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    while (true);
  }

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Rain Sensor Ready");
  display.display();
  delay(2000);
}

void loop() {
  int rainState = digitalRead(rainSensorPin);

  display.clearDisplay();

  if (rainState == LOW) {  // LOW usually means rain is detected
    display.setCursor(0, 0);
    display.setTextSize(2);
    display.println("It's");
    display.setCursor(0, 25);
    display.println("Raining!");
    Serial.println("Rain Detected!");
  } else {
    display.setCursor(0, 0);
    display.setTextSize(2);
    display.println("No Rain...");
    Serial.println("No Rain");
  }

  display.display();
  delay(1000);
}


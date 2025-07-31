#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int BUT1 = D0;
int BUT2 = D1;
int BUT3 = D2;
int BUT4 = D3;

int LED1 = D7;
int LED2 = D8;
int LED3 = D9;
int LED4 = D10;

int currentCount = 0;
int binCount = 0;

unsigned long lastTime = 0;
const long debounce = 150;

bool darkMode = false;

void setup() {
    pinMode(BUT1, INPUT_PULLUP);
    pinMode(BUT2, INPUT_PULLUP);
    pinMode(BUT3, INPUT_PULLUP);
    pinMode(BUT4, INPUT_PULLUP);

    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
    pinMode(LED4, OUTPUT);

    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.display("Glassy Bridge");
    delay(2000);
    display.clearDisplay();

    Serial.begin(9600);

    updateDisplayAndLEDs();
}

void updateDisplayAndLEDs() {
    if (darkMode) {
        display.setTextColor(WHITE, BLACK);
    } else {
        display.setTextColor(BLACK, WHITE);
    }

    display.clearDisplay();
    display.setCursor(0, 0);
    display.setTextSize(2);
    display.print("Count: ");
    display.println(currentCount);
    display.display();

    digitalWrite(LED1, (binCount & 0b1000) ? HIGH : LOW);
    digitalWrite(LED2, (binCount & 0b0100) ? HIGH : LOW);
    digitalWrite(LED3, (binCount & 0b0010) ? HIGH : LOW);
    digitalWrite(LED4, (binCount & 0b0001) ? HIGH : LOW);

    Serial.print("Current Count: ");
    Serial.print(currentCount);
    Serial.print(" (Binary: ");
    Serial.print(currentCount, BIN);
    Serial.print(" / ");
    Serial.print(binCount, BIN);
    Serial.print("), Mode: ");
    Serial.println(darkMode ? "Dark" : "Light");
}

void loop() {
    bool BUT1Pressed = (digitalRead(BUT1) == LOW);
    bool BUT2Pressed = (digitalRead(BUT2) == LOW);
    bool BUT3Pressed = (digitalRead(BUT3) == LOW);
    bool BUT4Pressed = (digitalRead(BUT4) == LOW);

    unsigned long currentTime = millis();

    if (currentTime - lastTime < debounce) {
        return;
    }

    if (BUT1Pressed) {
        currentCount++;
        binCount = currentCount % 4;
        updateDisplayAndLEDs();
        lastTime = currentTime;
    }
    else if (BUT2Pressed) {
        currentCount--;
        binCount = currentCount % 4;
        updateDisplayAndLEDs();
        lastTime = currentTime;
    }
    else if (BUT3Pressed) {
        currentCount = 0;
        binCount = currentCount % 4;
        updateDisplayAndLEDs();
        lastTime = currentTime;
    }
    else if (BUT4Pressed) {
        darkMode = !darkMode;
        updateDisplayAndLEDs();
        lastTime = currentTime;
    }
}
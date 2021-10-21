#include <Arduino.h>

const int KEY1_PIN = 12;
const int KEY2_PIN = 13;

const int BUTTON_ON_PIN = 5;
const int BUTTON_OFF_PIN = 6;
const int BUTTON_RED_PIN = 7;

bool isOn;

void pressButton(int pinNumber){
    digitalWrite(pinNumber, HIGH);
    delay(1000);
    digitalWrite(pinNumber, LOW);
}

void pressOnButton(){
    pressButton(BUTTON_ON_PIN);
}

void pressOffButton(){
    pressButton(BUTTON_OFF_PIN);
}

void pressRedButton(){
    pressButton(BUTTON_RED_PIN);
}

void setup(){
    pinMode(KEY1_PIN, INPUT_PULLUP);
    pinMode(KEY2_PIN, INPUT_PULLUP);

    pinMode(BUTTON_ON_PIN, OUTPUT);
    pinMode(BUTTON_OFF_PIN, OUTPUT);
    pinMode(BUTTON_RED_PIN, OUTPUT);

    isOn = false;
    pressOffButton();
}

void loop(){
    bool isKey1Attached = digitalRead(KEY1_PIN) == LOW;
    bool isKey2Attached = digitalRead(KEY2_PIN) == LOW;

    if (!isOn && isKey1Attached && isKey2Attached){
        pressOnButton();
        pressRedButton();

        isOn = true;
    }
    else if (isOn && (!isKey1Attached || !isKey2Attached)){
        pressOffButton();

        isOn = false;
    }

}


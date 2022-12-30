#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <microDS18B20.h>
#include <TimeLib.h>
#include <DS1307RTC.h>
#include "TinyDHT.h"

#define LCD_ADDRESS 0x3f
#define EEPROM_ADDRESS 0x50
#define RTC_ADDRESS 0x68
#define DS_ADDRESS 28 FF 6C D 1 17 5 F3
#define DHT_TYPE DHT11

#define DHT_ADDRESS
#define DS_PIN 14
#define DHT_PIN 15

#define RED_LED_PIN 10
#define GREEN_LED_PIN 9
#define BLUE_LED_PIN 6
#define WHITE_LED_PIN 5
#define DISPLAY_LED_PIN 11

#define ENCODER_A 2
#define ENCODER_B 4
#define ENCODER_SW 3

LiquidCrystal_I2C lcd(LCD_ADDRESS, 16, 2);
DHT dht(DHT_PIN, DHT_TYPE);
MicroDS18B20<DS_PIN> ds;


tmElements_t tm, tmSunrise, tmSunset;
int menue;
uint8_t maxRGBLight = 11, maxWhiteLight = 10, ledLightDay = 110, ledLightNight = 15, sunriseLength, sunsetLength;


int dht_h, dht_t;
float ds_t;

uint8_t buttonPressed, encoderTurnedLeft, encoderTurnedRight, encoderTurnedLeftHold, encoderTurnedRightHold;

void setup() {
  lcd.init();                      // initialize the lcd
  lcd.backlight();
  Serial.begin(9600);
  dht.begin();

  SetupISR();
}



void loop() {
  RTC.read(tm);
  ds_t = getTempDS();
  dht_h = dht.readHumidity();
  dht_t = dht.readTemperature(0);

  switch (menue) {
    case 0: {
        if (IsTurnedRightHold()) menue = 1;
        if (IsTurnedLeftHold()) menue = 5;
        break;

      }
    case 1: {
        if (IsTurnedRightHold()) menue = 2;
        if (IsTurnedLeftHold()) menue = 0;
        if (IsButtonPressed()) menue = 11;
        break;
      }
    case 11: {
        if (IsButtonPressed()) menue = 12;

        break;
      }
    case 12: {
        if (IsButtonPressed()) menue = 13;

        break;
      }
    case 13: {
        if (IsButtonPressed()) menue = 14;

        break;
      }
    case 14: {
        if (IsButtonPressed()) menue = 15;

        break;
      }
    case 15: {
        if (IsButtonPressed()) menue = 1;

        break;
      }
    case 2: {
        if (IsTurnedRightHold()) menue = 3;
        if (IsTurnedLeftHold()) menue = 1;
        if (IsButtonPressed()) menue = 21;

        break;
      }
    case 21: {
        if (IsButtonPressed()) menue = 22;

        break;
      }
    case 22: {
        if (IsButtonPressed()) menue = 23;

        break;
      }
      case 23: {
        if (IsButtonPressed()) menue = 2;

        break;
      }
    case 3: {
        if (IsTurnedRightHold()) menue = 4;
        if (IsTurnedLeftHold()) menue = 2;
        if (IsButtonPressed()) menue = 31;

        break;
      }
    case 31: {
        if (IsButtonPressed()) menue = 32;

        break;
      }
    case 32: {
        if (IsButtonPressed()) menue = 33;

        break;
      }
      case 33: {
        if (IsButtonPressed()) menue = 3;

        break;
      }
    case 4: {
        if (IsTurnedRightHold()) menue = 5;
        if (IsTurnedLeftHold()) menue = 3;
        if (IsButtonPressed()) menue = 41;

        break;
      }
    case 41: {
        if (IsButtonPressed()) menue = 42;

        break;
      }
    case 42: {
        if (IsButtonPressed()) menue = 4;

        break;
      }
    case 5: {
        if (IsTurnedRightHold()) menue = 0;
        if (IsTurnedLeftHold()) menue = 4;
        if (IsButtonPressed()) menue = 51;

        break;
      }
    case 51: {
        if (IsButtonPressed()) menue = 52;

        break;
      }
    case 52: {
        if (IsButtonPressed()) menue = 5;

        break;
      }
    default: {
        menue = 0;
        break;
      }
  }

  LcdPrinting();
  Serial.println(menue);
}

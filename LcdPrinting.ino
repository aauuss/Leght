void LcdPrinting() {

  switch (menue) {
    case 0: {
        lcd.clear();
        lcd.noCursor();
        lcd.noBlink();
        lcd.setCursor(0, 0);
        lcd.print(ds_t);
        lcd.print(" ");
        lcd.print(dht_t);
        lcd.print(" ");
        lcd.print(dht_h);
        lcd.print(" ");
        PrintTime(tm, 0, 1);
        lcd.setCursor(14, 1);
        lcd.print(menue);
        break;

      }
    case 1: {
        lcd.clear();
        lcd.noCursor();
        lcd.noBlink();
        lcd.setCursor(0, 0);
        lcd.print("Set current time");
        PrintTime(tm, 3, 1);
        break;
      }
    case 11: {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Set current time");
        PrintTime(tm, 3, 1);
        lcd.setCursor(4, 1);
        lcd.cursor();
        lcd.blink();

        break;
      }
    case 12: {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Set current time");
        PrintTime(tm, 3, 1);
        lcd.setCursor(7, 1);
        lcd.cursor();
        lcd.blink();

        break;
      }
    case 13: {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Set current Date");
        PrintDate(tm, 3, 1);
        lcd.setCursor(4, 1);
        lcd.cursor();
        lcd.blink();

        break;
      }
    case 14: {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Set current Date");
        PrintDate(tm, 3, 1);
        lcd.setCursor(7, 1);
        lcd.cursor();
        lcd.blink();

        break;
      }
    case 15: {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Set current Date");
        PrintDate(tm, 3, 1);
        lcd.setCursor(10, 1);
        lcd.cursor();
        lcd.blink();

        break;
      }

    case 2: {
        lcd.clear();
        lcd.noCursor();
        lcd.noBlink();
        lcd.setCursor(0, 0);
        lcd.print("Set sunrise time");
        PrintTime(tmSunrise, 2, 1);
        lcd.print("  L: ");
        PrintInt3(sunriseLength);

        break;
      }
    case 21: {
        lcd.clear();
        lcd.cursor();
        lcd.blink();
        lcd.setCursor(0, 0);
        lcd.print("Set sunrise time");
        PrintTime(tmSunrise, 2, 1);
        lcd.print("  L: ");
        PrintInt3(sunriseLength);
        lcd.setCursor(3, 1);

        break;
      }
    case 22: {
        lcd.clear();
        lcd.cursor();
        lcd.blink();
        lcd.setCursor(0, 0);
        lcd.print("Set sunrise time");
        PrintTime(tmSunrise, 2, 1);
        lcd.print("  L: ");
        PrintInt3(sunriseLength);
        lcd.setCursor(6, 1);
        break;
      }
    case 23: {
        lcd.clear();
        lcd.cursor();
        lcd.blink();
        lcd.setCursor(0, 0);
        lcd.print("Set sunrise time");
        PrintTime(tmSunrise, 2, 1);
        lcd.print("  L: ");
        PrintInt3(sunriseLength);
        lcd.setCursor(14, 1);
        break;
      }
    case 3: {
        lcd.clear();
        lcd.noCursor();
        lcd.noBlink();
        lcd.setCursor(0, 0);
        lcd.print("Set sunset time");
        PrintTime(tmSunset, 2, 1);
        lcd.print("  L: ");
        PrintInt3(sunsetLength);

        break;
      }
    case 31: {
        lcd.clear();
        lcd.cursor();
        lcd.blink();
        lcd.setCursor(0, 0);
        lcd.print("Set sunset time");
        PrintTime(tmSunset, 2, 1);
        lcd.print("  L: ");
        PrintInt3(sunsetLength);
        lcd.setCursor(3, 1);

        break;
      }
    case 32: {
        lcd.clear();
        lcd.cursor();
        lcd.blink();
        lcd.setCursor(0, 0);
        lcd.print("Set sunset time");
        PrintTime(tmSunset, 2, 1);
        lcd.print("  L: ");
        PrintInt3(sunsetLength);
        lcd.setCursor(6, 1);

        break;
      }
    case 33: {
        lcd.clear();
        lcd.cursor();
        lcd.blink();
        lcd.setCursor(0, 0);
        lcd.print("Set sunset time");
        PrintTime(tmSunset, 2, 1);
        lcd.print("  L: ");
        PrintInt3(sunsetLength);
        lcd.setCursor(14, 1);

        break;
      }
    case 4: {
        lcd.clear();
        lcd.noCursor();
        lcd.noBlink();
        lcd.setCursor(0, 0);
        lcd.print("Set Brightness");
        lcd.setCursor(0, 1);
        lcd.print("RGB: ");
        PrintInt3(maxRGBLight);
        lcd.print(" W: ");
        PrintInt3(maxWhiteLight);
        break;
      }
    case 41: {
        lcd.clear();
        lcd.cursor();
        lcd.blink();
        lcd.setCursor(0, 0);
        lcd.print("Set Brightness");
        lcd.setCursor(0, 1);
        lcd.print("RGB: ");
        PrintInt3(maxRGBLight);
        lcd.print(" W: ");
        PrintInt3(maxWhiteLight);
        lcd.setCursor(7, 1);

        break;
      }
    case 42: {
        lcd.clear();
        lcd.cursor();
        lcd.blink();
        lcd.setCursor(0, 0);
        lcd.print("Set Brightness");
        lcd.setCursor(0, 1);
        lcd.print("RGB: ");
        PrintInt3(maxRGBLight);
        lcd.print(" W: ");
        PrintInt3(maxWhiteLight);
        lcd.setCursor(14, 1);

        break;
      }
    case 5: {
        lcd.clear();
        lcd.noCursor();
        lcd.noBlink();
        lcd.setCursor(0, 0);
        lcd.print("Set Brightness");
        lcd.setCursor(0, 1);
        lcd.print("D: ");
        PrintInt3(ledLightDay);
        lcd.print("  N: ");
        PrintInt3(ledLightNight);

        break;
      }
    case 51: {
        lcd.clear();
        lcd.cursor();
        lcd.blink();
        lcd.setCursor(0, 0);
        lcd.print("Set Brightness");
        lcd.setCursor(0, 1);
        lcd.print("D: ");
        PrintInt3(ledLightDay);
        lcd.print("  N: ");
        PrintInt3(ledLightNight);
        lcd.setCursor(5, 1);

        break;
      }
    case 52: {
        lcd.clear();
        lcd.cursor();
        lcd.blink();
        lcd.setCursor(0, 0);
        lcd.print("Set Brightness");
        lcd.setCursor(0, 1);
        lcd.print("D: ");
        PrintInt3(ledLightDay);
        lcd.print("  N: ");
        PrintInt3(ledLightNight);
        lcd.setCursor(13, 1);
        break;
      }
    default: {
        break;
      }

  }
}

void PrintTime(tmElements_t _tm, int x, int y) {
  lcd.setCursor(x, y);

  if (_tm.Hour < 10) {
    lcd.print(' ');
    lcd.print(_tm.Hour);
  }
  else {
    lcd.print(_tm.Hour);
  }

  lcd.print(":");
  if (_tm.Minute < 10) {
    lcd.print('0');
    lcd.print(_tm.Minute);
  }
  else {
    lcd.print(_tm.Minute);
  }
}

void PrintDate(tmElements_t _tm, int x, int y) {
  lcd.setCursor(x, y);

  if (_tm.Day < 10) {
    lcd.print(' ');
    lcd.print(_tm.Day);
  }
  else {
    lcd.print(_tm.Day);
  }

  lcd.print("/");
  if (_tm.Month < 10) {
    lcd.print(' ');
    lcd.print(_tm.Month);
  }
  else {
    lcd.print(_tm.Month);
  }

  lcd.print("/");
  lcd.print(_tm.Year);
}

void PrintInt3(uint8_t _data) {
  String _str = String(_data);
  if (_data < 10) {
    lcd.print('  ');
    lcd.print(_str);
    return;
  }
  if (_data < 100) {
    lcd.print(' ');
    lcd.print(_str);
    return;
  }
  lcd.print(_str);
}

void PrintInt4(uint8_t _data) {
  String _str = String(_data);
  if (_data < 10) {
    lcd.print('   ');
    lcd.print(_str);
    return;
  }
  if (_data < 100) {
    lcd.print('  ');
    lcd.print(_str);
    return;
  }
  if (_data < 1000) {
    lcd.print(' ');
    lcd.print(_str);
    return;
  }
  lcd.print(_str);
}

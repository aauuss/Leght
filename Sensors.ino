uint32_t dsDelay;

float getTempDS() {
  if (millis() - dsDelay >= 800) {
    dsDelay = millis();

    float _temp;
    // читаем прошлое значение
    if (ds.readTemp()) _temp = ds.getTemp();
    else  _temp = 0;

    // запрашиваем новое измерение
    ds.requestTemp();
    return _temp;
  }
}

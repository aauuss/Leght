

void SetupISR() {
  EICRA |= (1 << ISC01) | (1 << ISC11);
  EIMSK |= (1 << INT0) | (1 << INT1);
}


ISR(INT0_vect) {
  ResetEncoderFlags();
  if (PIND & (1 << PD4)) {       //поворот вправо
    if (~PIND & (1 << PD3))     //с нажатием
      encoderTurnedRightHold = 1;    
    else encoderTurnedRight = 1;  //без нажатия
    }
  else { //поворот влево
    if (~PIND & (1 << PD3)) {  //с нажатием
      encoderTurnedLeftHold = 1;
    }
    else encoderTurnedLeft = 1; //без нажатия
    }
}

ISR(INT1_vect) {
  ResetEncoderFlags();
  buttonPressed = 1;
}

void ResetEncoderFlags() {
  encoderTurnedLeft = 0;
  encoderTurnedRight = 0;
  encoderTurnedLeftHold = 0;
  encoderTurnedRightHold = 0;
  buttonPressed = 0;

}

boolean IsTurnedLeft() {
  if (encoderTurnedLeft) {
    ResetEncoderFlags();
    return true;
  }
  return false;
}

boolean IsTurnedRight() {
  if (encoderTurnedRight) {
    ResetEncoderFlags();
    return true;
  }
  return false;
}

boolean IsTurnedLeftHold() {
  if (encoderTurnedLeftHold) {
    ResetEncoderFlags();
    return true;
  }
  return false;
}

boolean IsTurnedRightHold() {
  if (encoderTurnedRightHold) {
    ResetEncoderFlags();
    return true;
  }
  return false;
}


boolean IsButtonPress() {
  return ((~PIND & (1 << PD3)));
}

boolean IsButtonPressed() {
  if (buttonPressed && (PIND & (1 << PD3))) {
    ResetEncoderFlags();
    return true;
  }
  return false;
}

int EncoderTick() {
  if (IsTurnedLeft()) return 1;
  if (IsTurnedRight()) return 2;
  if (IsTurnedLeftHold()) return 3;
  if (IsTurnedRightHold()) return 4;
  if (IsButtonPressed()) return 5;
  return 0;
}

boolean EncoderTurnedLeft() {
  return (EncoderTick() == 1);
}

boolean EncoderTurnedRight() {
  return (EncoderTick() == 2);
}

boolean EncoderTurnedLeftHold() {
  Serial.println("-");
  return (EncoderTick() == 3);
}

boolean EncoderTurnedRightHold() {
  return (EncoderTick() == 4);
}

boolean EncoderButtonPressed() {
  return (EncoderTick() == 5);
}

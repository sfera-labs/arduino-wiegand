/*
  Wiegand.cpp - Wiegand Arduino library

    Copyright (C) 2022 Sfera Labs S.r.l. - All rights reserved.

    For information, see:
    http://www.sferalabs.cc/

  This code is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.
  See file LICENSE.txt for further informations on licensing terms.
*/

#include "Wiegand.h"
#include <Arduino.h>

#include "libs/wiegand-c-lib/wiegand.c"

Wiegand::Wiegand(int pinD0, int pinD1) {
  _pinD0 = pinD0;
  _pinD1 = pinD1;
}

unsigned long wiegandMicros() {
  return micros();
}

bool Wiegand::setup(void (*cbData0)(void),
            void (*cbData1)(void),
            bool pullUp,
            unsigned long pulseIntervalMin_usec,
            unsigned long pulseIntervalMax_usec,
            unsigned long pulseWidthMin_usec,
            unsigned long pulseWidthMax_usec) {
  ::pinMode(_pinD0, pullUp ? INPUT_PULLUP : INPUT);
  ::pinMode(_pinD1, pullUp ? INPUT_PULLUP : INPUT);
  ::attachInterrupt(digitalPinToInterrupt(_pinD0), cbData0, CHANGE);
  ::attachInterrupt(digitalPinToInterrupt(_pinD1), cbData1, CHANGE);
  return true;
}

void Wiegand::onData0() {
  wiegandOnData(&_w, 0, ::digitalRead(_pinD0));
}

void Wiegand::onData1() {
  wiegandOnData(&_w, 1, ::digitalRead(_pinD1));
}

int Wiegand::getData(uint64_t* data) {
  return wiegandGetData(&_w, data);
}

int Wiegand::getNoise() {
  return wiegandGetNoise(&_w);
}

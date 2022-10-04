/*
  Wiegand.h - Wiegand Arduino library

    Copyright (C) 2022 Sfera Labs S.r.l. - All rights reserved.

    For information, see:
    http://www.sferalabs.cc/

  This code is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.
  See file LICENSE.txt for further informations on licensing terms.
*/

#include "libs/wiegand-c-lib/wiegand.h"

class Wiegand {
  public:
    Wiegand(int, int);
    bool setup(void (*onData0)(void),
            void (*onData1)(void),
            bool pullUp,
            unsigned long pulseIntervalMin_usec,
            unsigned long pulseIntervalMax_usec,
            unsigned long pulseWidthMin_usec,
            unsigned long pulseWidthMax_usec);
    void onData0();
    void onData1();
    int getData(uint64_t* data);
    int getNoise();

  private:
    int _pinD0;
    int _pinD1;
    wiegandItf _w;
};

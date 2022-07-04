#include <Wiegand.h>

#define PIN_D0 0
#define PIN_D1 1

Wiegand w(PIN_D0, PIN_D1);

uint64_t data;
int bits;
int noise;

char buff[20];

void onData0() {
  w.onData0();
}

void onData1() {
  w.onData1();
}

void setup() {
  Serial.begin(9600);
  while(!Serial);

  w.setup(
    onData0,
    onData1,
    false,  // disable pins internal pull-up, use external
    700,    // min pulse interval (usec)
    2700,   // max pulse interval (usec)
    10,     // min pulse width (usec)
    150     // max pulse width (usec)
  );

  Serial.println("== Ready ==");
}

void loop() {
  bits = w.getData(&data);
  noise = w.getNoise();

  if (bits > 0) {
    Serial.print("Bits: ");
    Serial.println(bits);
    Serial.print("Data: ");
    println64bitHex(data);
    Serial.println();
  }
  if (noise != 0) {
    Serial.print("Noise: ");
    Serial.println(noise);
    Serial.println();
  }

  delay(100);
}

void println64bitHex(uint64_t val) {
  sprintf(buff, "0x%08lx%08lx",
    ((uint32_t) ((val >> 32) & 0xFFFFFFFF)),
    ((uint32_t) (val & 0xFFFFFFFF)));
  Serial.println(buff);
}

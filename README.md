# Wiegand Arduino library

Simple Arduino library for reading data from Wiegand devices (keypads, card readers, biometric readers, ...).    
It is agnostic to data format (parity bits, card data, facility code, etc. are not interpreted) and provides for noise detection and filtering.

For functional details read the documentation of [the C library](https://github.com/sfera-labs/wiegand-c-lib#readme) this library is based on.

To install this library:

- [Download this repo](https://github.com/sfera-labs/arduino-wiegand/archive/refs/heads/master.zip)
- Open the Arduino IDE
- Go to the menu *Sketch* > *Include Library* > *Add .ZIP Library...*
- Select the downloaded zip file

For a quick start, refer to the [examples](./examples).

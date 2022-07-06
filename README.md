# Wiegand Arduino library

Simple Arduino library for reading data from Wiegand devices (keypads, card readers, biometric readers, ...).    
It is agnostic to data format (parity bits, card data, facility code, etc. are not interpreted) and provides for noise detection and filtering.

For functional details read the documentation of [the C library](https://github.com/sfera-labs/wiegand-c-lib#readme) this library is based on.

To install this library:
```
cd <your_arduino_libraries_dir>
git clone --depth 1 --recursive https://github.com/sfera-labs/arduino-wiegand
```

For a quick start, refer to the [examples](./examples).

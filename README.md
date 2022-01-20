# LoRa-Compatible Electronic HazWind Windsock (BETA BRANCH)

## What's this?

This version of GNESAC's Electronic HazWind windsock utilizes the [LoRaWAN](https://www.thethingsnetwork.org/docs/lorawan/what-is-lorawan/) communication protocol. It is a warning system that tells the user the most appropriate evacuation route (labeled exit) in case of a fire inside the workplace, given the wind direction reading from the windsock's rotation. The message is then displayed on a P10 LED matrix.

## Dependencies

- [DMD Library](http://www.freetronics.com/dmd-library): A library for driving the Freetronics 512 pixel dot matrix LED display "DMD", a 32 x 16 layout.
- [TimerOne](https://github.com/PaulStoffregen/TimerOne): A collection of routines for configuring the 16 bit hardware timer called Timer1 on the ATmega168/328.
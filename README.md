# Clamp15
 Simulate remotely clamp15 signal with Arduino and relay module.
 
 ## Wiring:
![relayModule](images/SCR-20230613-jomn.png)
![switch](images/SCR-20230613-jqiu.jpeg)

## Arduino
An Arduino nano and relay module with 4 relays (see picture above) was used to simulate and replace the guitar 3-step switch.
The project for Arduino is in [PlatformIoClamp15](PlatformIoClamp15).

See https://docs.platformio.org/en/latest/ for more info.

## Node-red
Node-red was used to simply send the commands that need to be executed to Arduino via a simple interface.

See https://nodered.org/docs/ for installation more info.

## How to
- The Arduino box must be connected to one target UBS port 

- See [node-red markdown](NodeRed/README.md) for configuring the node-red
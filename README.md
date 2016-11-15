# TrackFPV
Use your Fatshark or Skyzone goggles as a virtual reality headset.

Fast overview: Use an Arduino Micro as a Joystick for OpenTrack with the input of your FPV-Headtracker.

#Hardware:
•	Arduino Micro (ATmega32U4 = featuring a built-in USB which makes the Micro recognizable as a joystick)
•	3,5 mm phone jack from your goggle
•	Mirroring the Computer-Screen to the goggle with a HDMI to AV converter

##Software:
•	install the latest OpenTrack software https://github.com/opentrack/opentrack/releases
•	install latest Arduino IDE and drivers

###Libraries used in this project:
•	Joystick.h https://github.com/MHeironimus/ArduinoJoystickLibrary
•	CPPM.h https://github.com/jmparatte/CPPM

###Installation: 1. prepare Hardware. Ground to Ground and the PPM-Pin to D4 (it´s the ICP-Pin) 
2. Install the libraries 
3. Upload the sketch to the Arduino 
4. Check if the Arduino is detected from the computer (Windows Control Panel >> Hardware >> Devices >> Arduino Micro 
5. Start OpenTrack and import the "TrackFPV.ini" profile 
6. Choose the Arduino as the joystick input 
7. Press the "Tracker" Button on your FPV goggle and klick immediately "Start" 
8. Enjoy your VR Headset

Bug and Features: Please report bugs and wishes to me. Thanks!

Tested with Arduino Micro, OpenTrack2.3 and Skyzone V2 and RealFlight 7 on Win10_64bit


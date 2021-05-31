# IRremote_Panasonic_Conversion
Decodes the IR signals from a VerizonFios TV remote 

This is part of an effort to create an infrared-controlled window shade using an Arduino Nano 33 iOt, a fun side project as I learn the process.

Parts include an IR sensor, male-to-male jumper wires, 9V breadboard power supply (not plugged in) and mini USB cable.

The purpose is to use the existing TV remote to control a motor, but the remote I have doesn't specify the manufacturer, so I had to read and interpret the codes coming from the remote. Even though the labeling is a little confusing, turns out to be a great introduction to breadboard prototyping, couldn't be much easier! 

Pin Connections:

*Arduino* 

Pin 2 to Signal on IR sensor

3.3v to positive rail

Ground to negative rail

*IR Sensor*

Signal to Pin 2

Positive to positive rail

Ground to negative rail

Breadboard power supply connecting both pairs of rails

----------------------------

*The Ken Shirriff IR Remote library for the Arduino IDE has been replaced with the Armin Joachimsmeyer version 3.3, so take note when you realize ALL the tutorials still reference the one by Shirriff!*

Also used https://github.com/Arduino-IRremote/Arduino-IRremote and the detailed tutorial at https://www.makerguides.com/ir-receiver-remote-arduino-tutorial/ by Benne de Bakker to identify the remote's protocols.

I removed the "blink" sections from the sketch, since they're redundant- the Arduino and IR sensor both blink by default when they detect a signal. Also some of the manufacturer names listed were throwing errors for some reason, so I removed those as well. 

Once up-and-running, I could see that the Verizon Fios remote uses Panasonic hexadecimals. There's probably a better way to go about matching up the codes with the buttons, but I went through the tedious manual process of hitting each button, copying the hexadecimal, pasting with the prefix "0x" and adding a custom description for each. The result is an artisinal, hand-curated conversion list that translates each code into human language, including some handy emojis:

VOL+
VOL-

CH+
CH-

FiOS TV
POWER🔘STB
POWER🔘TV

▶
▶

⏸
⏸
❤
❤
❤
☆
☆
☆

Mute
*
*
*

A/V
A/V
A🔺
A🔺
A🔺


C🔴
C🔴
C🔴
🆗
🆗
🆗

This level of detail is completely unnecessary for controling a stepper motor, but it was a lot of fun.



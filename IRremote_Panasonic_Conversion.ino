/* Finding the key codes for your remote. More info: https://www.makerguides.com */

/* IR remote and receiver Arduino example code. Print key values in the Serial Monitor. More info: https://www.makerguides.com */

#include <IRremote.h> // include the IRremote library

#define RECEIVER_PIN 2 // define the IR receiver pin
IRrecv receiver(RECEIVER_PIN); // create a receiver object of the IRrecv class
decode_results results; // create a results object of the decode_results class
unsigned long key_value = 0; // variable to store the key value

void setup() {
  Serial.begin(9600); // begin serial communication with a baud rate of 9600
  receiver.enableIRIn(); // enable the receiver
  //receiver.blink13(true); // enable blinking of the built-in LED when an IR signal is received
}

void loop() {
  if (receiver.decode(&results)) { // decode the received signal and store it in results
    if (results.value == 0xFFFFFFFF) { // if the value is equal to 0xFFFFFFFF
      results.value = key_value; // set the value to the key value
    }
    switch (results.value) { // compare the value to the following cases
      case 0x40100BCB: // if the value is equal to 40100BCB
        Serial.println("POWER🔘TV"); // print "POWER" in the Serial Monitor
        break;
      case 0x40100040:
        Serial.println("VOL+");
        break;
      case 0xD6599F48:
        Serial.println("FUNC/STOP");
        break;
      case 0xFEF03E2C:
        Serial.println("⏮");
        break;
      case 0xDC18602C:
        Serial.println(">");
        break ;
      case 0x9578646A:
        Serial.println("<");
        break ;  
      case 0x66E97044:
        Serial.println("⏭");
        break ;
      case 0x5A1A483D:
        Serial.println("DOWN");
        break ;
      case 0x40100848:
        Serial.println("VOL-");
        break ;
      case 0x2C2E80FF:
        Serial.println("UP");
        break ;
      case 0x6E56F924:
        Serial.println("0");
        break ;
      case 0x70F06FB7:
        Serial.println("FiOS TV");
        break ;
      case 0x736ED82E:
        Serial.println("POWER🔘STB");
        break ;
      case 0x92DF9279:
        Serial.println("1");
        break ;
      case 0x87CDD0EF:
        Serial.println("2");
        break ;
      case 0x37788763:
        Serial.println("3");
        break ;
      case 0xA519853B:
        Serial.println("4");
        break ;
      case 0x5CDD8FBD:
        Serial.println("5");
        break ;
      case 0x42DD49:
        Serial.println("6");
        break ;
      case 0x31BB009F:
        Serial.println("7");
        break ;
      case 0x153F90A7:
        Serial.println("8");
        break ;
      case 0x6872B60C:
        Serial.println("9");
        break ;
      case 0xA21B9595:
        Serial.println("*");
        break ;
      case 0xE61D2DFB:
        Serial.println("#");
        break ;  
      case 0x2935B9A7:
        Serial.println("Exit");
        break ;
        
      case 0xC04793FD:
        Serial.println("+");
        break ;
      case 0x87AE0368:
        Serial.println("☆");
        break ;
        case 0x9F7ED203:
        Serial.println("❤");
        break ;
      case 0xF06561F3:
        Serial.println("Options");
        break ;
        case 0x19EB3488:
        Serial.println("Menu");
        break ;
      case 0xE9C74319:
        Serial.println("Guide");
        break ;
        case 0x4666CC0D:
        Serial.println("Info");
        break ;
      case 0x401004C4:
        Serial.println("Mute");
        break ;

      case 0xE28725E3:
        Serial.println("Last");
        break ;
      case 0x8A67822:
        Serial.println("CH+");
        break ;
      case 0xFBACE420:
        Serial.println("CH-");
        break ;
      case 0xAE7CDBE:
        Serial.println("DVR");
        break ;

      case 0x313599EC:
        Serial.println("▶");
        break ;
      case 0xD922D768:
        Serial.println("⏸");
        break ;
      case 0x7A68C48:
        Serial.println("Prev");
        break ;
      case 0xBDD4796D:
        Serial.println("Next");
        break ;

      case 0xF16DB763:
        Serial.println("REC 🔴");
        break ;
      case 0xDCC99F1F:
        Serial.println("A🔺");
        break ;
      case 0xCFEF4134:
        Serial.println("B🟦");
        break ;
      case 0xFC67AFAE:
        Serial.println("C🔴");
        break ;
      case 0xEFBE2D68:
        Serial.println("D🔸");
        break ;
        case 0x40100A0A:
        Serial.println("A/V");
        break ;
      case 0xAC101205:
        Serial.println("PIP");
        break ;
     
      case 0xCB3CC07F:
        Serial.println("🆗");
        break ;

    }
    key_value = results.value; // store the value as key_value
    receiver.resume(); // reset the receiver for the next code
  }
}

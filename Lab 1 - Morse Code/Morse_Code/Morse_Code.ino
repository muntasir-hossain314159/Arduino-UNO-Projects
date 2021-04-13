const int dotRed = 5;                 //digital i/o pin number for "R" on the RGB LED
const int dashGreen = 4;              //digital i/o pin number for "G" on the RGB LED
const int buttonWire = 8;             //digital i/o pin number for "S" on the push button

int i = 0;                            //array index counter
const char firstName[] = "Muntasir";  //string storing first name


void setup() {

  pinMode(dotRed, OUTPUT);            //set pinMode of dotRed to OUTPUT
  pinMode(dashGreen, OUTPUT);         //set pinMode of dashGreen to OUTPUT

  pinMode(buttonWire, INPUT);         //set pinMode of buttonWire to INPUT

}

void loop() {

  int buttonPress = !digitalRead(buttonWire);   //set buttonPress equal to the not of the value read from buttonWire

  if (buttonPress)                              //true if the button is pressed
  {
    switch (firstName[i])                       //switch-case condition: the character stored in the ith index of the array
    {
      case 'M':                                 //morse code signal for 'M'
        digitalWrite(dashGreen, HIGH);          //Green LED is HIGH for 200 ms
        delay(200);
        digitalWrite(dashGreen, LOW);           //Green LED is LOW for 200 ms - this causes the light to flash on and then off
        delay(200);
        digitalWrite(dashGreen, HIGH);
        delay(200);
        digitalWrite(dashGreen, LOW);
        delay(1000);                            //Waits 1000 ms before the next letter is outputted
        break;

      //same principle as above (case 'M')   
      case 'u':                                 //morse code signal for 'u'
        digitalWrite(dotRed, HIGH);
        delay(200);
        digitalWrite(dotRed, LOW);
        delay(200);
        digitalWrite(dotRed, HIGH);
        delay(200);
        digitalWrite(dotRed, LOW);
        delay(200);
        digitalWrite(dashGreen, HIGH);
        delay(200);
        digitalWrite(dashGreen, LOW);
        delay(1000);
        break;

      case 'n':                                 //morse code signal for 'n'
        digitalWrite(dashGreen, HIGH);
        delay(200);
        digitalWrite(dashGreen, LOW);
        delay(200);
        digitalWrite(dotRed, HIGH);
        delay(200);
        digitalWrite(dotRed, LOW);
        delay(800);
        break;

      case 't':                                 //morse code signal for 't'
        digitalWrite(dashGreen, HIGH);
        delay(200);
        digitalWrite(dashGreen, LOW);
        delay(1000);
        break;

      case 'a':                                 //morse code signal for 'a'
        digitalWrite(dotRed, HIGH);
        delay(200);
        digitalWrite(dotRed, LOW);
        delay(200);
        digitalWrite(dashGreen, HIGH);
        delay(200);
        digitalWrite(dashGreen, LOW);
        delay(1000);
        break;

      case 's':                                 //morse code signal for 's'
        digitalWrite(dotRed, HIGH);
        delay(200);
        digitalWrite(dotRed, LOW);
        delay(200);
        digitalWrite(dotRed, HIGH);
        delay(200);
        digitalWrite(dotRed, LOW);
        delay(200);
        digitalWrite(dotRed, HIGH);
        delay(200);
        digitalWrite(dotRed, LOW);
        delay(1000);
        break;

      case 'i':                                 //morse code signal for 'i'
        digitalWrite(dotRed, HIGH);
        delay(200);
        digitalWrite(dotRed, LOW);
        delay(200);
        digitalWrite(dotRed, HIGH);
        delay(200);
        digitalWrite(dotRed, LOW);
        delay(1000);
        break;

      case 'r':                                 //morse code signal for 'r'
        digitalWrite(dotRed, HIGH);
        delay(200);
        digitalWrite(dotRed, LOW);
        delay(200);
        digitalWrite(dashGreen, HIGH);
        delay(200);
        digitalWrite(dashGreen, LOW);
        delay(200);
        digitalWrite(dotRed, HIGH);
        delay(200);
        digitalWrite(dotRed, LOW);
        delay(1000);
        break;
    }

    i++;                                        //increment counter

    if (i == 8)                                 //exit from the program if the end of the string is reached
      exit(0);
  }
}

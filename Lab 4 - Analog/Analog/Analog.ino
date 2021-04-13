const int redLed = 5;             //Digital PWM pin for red LED

const int x_axisJoystick = A0;    //analog input pin for x-axis of the joystick
const int y_axisJoystick = A1;    //analog input pin for y-axis of the joystick
const int temperatureSensor = A2; //analog input pin for the temperature sensor
const int lightSensor = A3;       //analog input pin for the light sensor

int adcValue;
double voltage;

char input = 'X';       //default value of analog input device: x-axis of joystick
char outputType = 'R';  //default value of output type: raw ADC value

void setup() {

  Serial.begin(9600); //set baud rate
}

void loop() {

  char tempInput;   //stores input from user
  int pwmValue;     //stores the calculated duty cycle (PWM) from the raw ADC value

  if (Serial.available() == 1)  //if the buffer contains 1 character
  {
    tempInput = Serial.read();  //read the character and store it in tempInput
    Serial.println(tempInput);  //print the character

    if (tempInput == 'R' || tempInput == 'V') //set outputType equal to tempInput if tempInput contains the apporpriate key character ('R' or 'V')
    {
      outputType = tempInput;
    }

    else                                      //else set input to tempInput
    {
      input = tempInput;
    }
  }

  switch (input) //switch-case statement for analog input device
  {
    case 'T':                                       //temperature sensor
      adcValue = analogRead(temperatureSensor);     //reads the analog input from sensor and stores the raw ADC value 
      pwmValue = (255  * (adcValue - 123)) / 367;   //calculates the corresponding duty cycle for that raw ADC value
      analogWrite(redLed, pwmValue);                //writes to the output device (redLed) the calculated duty cycle to vary the brighness of the LED
      break;
    case 'X':                                       //x-axis of joystick
      adcValue = analogRead(x_axisJoystick);
      pwmValue = 255 * adcValue / 1023;
      analogWrite(redLed, pwmValue);
      break;
    case 'Y':                                       //y-axis of joystick
      adcValue = analogRead(y_axisJoystick);
      pwmValue = 255 * adcValue / 1023;
      analogWrite(redLed, pwmValue);
      break;
    case 'L':                                       //light sensor
      adcValue = analogRead(lightSensor);
      pwmValue = 255 * adcValue / 1023 ;
      analogWrite(redLed, pwmValue);
      break;
    default:                                        //invalid character inputted
      Serial.println("Invalid Input");
  }

  voltage = 5.0 * adcValue / 1023;  //calculate the corresponding voltage from the raw ADC value

  switch (outputType) //show appropriate output depending on the outputType chosen by the user
  {
    case 'R':
      Serial.print("Raw ADC Value: ");   //print Raw ADC Value
      Serial.println(adcValue);
      break;
    case 'V':
      Serial.print("Voltage: ");         //print Voltage
      Serial.println(voltage);
      break;
  }

}

#include <TimerOne.h>

const int redLed = 4;
const int blueLed = 2;
const int greenLed = 3;

int task = 1;
char values[100];

int counterTask1 = 0;
int counteriTask2 = 0;
int counterjTask2 = 1;
int counterTask3 = 0;
bool task1Complete = false;
bool task2Complete = true;
bool task3Complete = true;

char temp; 

void setup(void)
{ 
  pinMode(redLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(greenLed, OUTPUT);

  Timer1.initialize(100000);
  Timer1.attachInterrupt(setTask);
  interrupts();

  Serial.begin(9600);

  randomSeed(analogRead(0));
}

void setTask()
{
  task++;

  if (task == 4)
    task = 1;
}



void loop(void)
{
  switch (task)
  {
    case 1:
      {
        digitalWrite(greenLed, LOW);
        digitalWrite(redLed, HIGH);
        unsigned int randomValue;
        if (!task1Complete && task2Complete && task3Complete)  //initialize values[] with randomly generated numbers
        {
          randomValue = random(0, 256);
          values[counterTask1] = randomValue;
          counterTask1++;
        }
        if (counterTask1 == 100)
        {
          counterTask1 = 0;
          task1Complete = true;
          task2Complete = false;
        }

        break;
      }

    case 2:
      {
        digitalWrite(redLed, LOW);
        digitalWrite(blueLed, HIGH);

        if (task1Complete && !task2Complete && task3Complete)
        {
          if (values[counterjTask2] < values[counteriTask2])   //sort array in ascending order
          {
            temp = values[counteriTask2];
            values[counteriTask2] = values[counterjTask2];
            values[counterjTask2] = temp;
          }
          counterjTask2++;

          if (counterjTask2 == 100)
          {
            counterjTask2 = ++counteriTask2 + 1;
            
            if (counteriTask2 == 99)
            {
              counteriTask2 = 0;
              counterjTask2 = 1;
              task2Complete = true;
              task3Complete = false;
            }
          }
        }
        break;
      }

    case 3:
      {
        digitalWrite(blueLed, LOW);
        digitalWrite(greenLed, HIGH);
        if (task1Complete && task2Complete && !task3Complete)  //print the values in the array
        {
          Serial.print("Values ");
          Serial.print(counterTask3 + 1);
          Serial.print(": ");
          Serial.println(values[counterTask3], DEC);
          counterTask3++;
        }

        if (counterTask3 == 100)
        {
          counterTask3 = 0;
          task1Complete = false;
          task3Complete = true;
        }
        break;
      }
  }
}

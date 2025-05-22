#include <Arduino.h>

const int IN1[] = {9, 10, 11, 12};
const int IN2[] = {5, 6, 7, 8};
const int IN3[] = {A0, A1, A2, A3};

const String switchStateUp = "KL.15 on & KL.S on";
const String switchStateMiddle = "KL.15 off & KL.S on";
const String switchStateDown = "KL.15 off & KL.S off";
const String separator = "|";

const int upStates[4] = {0, 1, 1, 0};
const int middleStates[4] = {1, 1, 1, 1};
const int downStates[4] = {1, 0, 0, 1};

class RelayModule
{
public:
  int moduleNr;
  int pins[4];

  RelayModule(int nr, const int pinArray[])
  {
    moduleNr = nr;
    for (int i = 0; i < 4; i++)
    {
      pins[i] = pinArray[i];
      pinMode(pins[i], OUTPUT);
    }
  }

  void switchUp()
  {
    for (int i = 0; i < 4; i++)
    {
      digitalWrite(pins[i], upStates[i]);
    }
    Serial.println(moduleNr + separator + switchStateUp);
  }

  void switchMiddle()
  {
    for (int i = 0; i < 4; i++)
    {
      digitalWrite(pins[i], middleStates[i]);
    }
    Serial.println(moduleNr + separator + switchStateMiddle);
  }

  void switchDown()
  {
    for (int i = 0; i < 4; i++)
    {
      digitalWrite(pins[i], downStates[i]);
    }
    Serial.println(moduleNr + separator + switchStateDown);
  }
};

RelayModule module1(1, IN1);
RelayModule module2(2, IN2);
RelayModule module3(3, IN3);

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  module1.switchUp();
  module2.switchUp();
  module3.switchUp();
}

int comand = -1;

void loop()
{
  if (Serial.available() > 0)
  {
    comand = Serial.parseInt();

    // Do something with the data - like print it
    Serial.print("Comand received is: ");
    Serial.println(comand);
  }

  switch (comand)
  {
  case 11:
    module1.switchUp();
    break;
  case 12:
    module1.switchMiddle();
    break;
  case 13:
    module1.switchDown();
    break;
  case 21:
    module2.switchUp();
    break;
  case 22:
    module2.switchMiddle();
    break;
  case 23:
    module2.switchDown();
    break;
  case 31:
    module3.switchUp();
    break;
  case 32:
    module3.switchMiddle();
    break;
  case 33:
    module3.switchDown();
    break;

  default:
    break;
  }

  delay(100);
}

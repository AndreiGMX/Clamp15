#include <Arduino.h>

const int IN[] = {8, 9, 10, 11};

const int defaultStates[4] = {1, 1, 1, 1};
const int upStates[4] = {0, 1, 1, 0};
const int middleStates[4] = {1, 1, 1, 1};
const int downStates[4] = {1, 0, 0, 1};

void relayToSwitch(const int position[])
{
  for (int i = 0; i < 4; i++)
  {
    pinMode(IN[i], OUTPUT);
    digitalWrite(IN[i], position[i]);
  }
}

void setup()
{
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  relayToSwitch(upStates);
   Serial.println("KL.15 on & KL.S on");
}

void loop()
{
  // Serial.println("Enter command:");
  while (Serial.available() == 0)
  {
  }                                   // wait for data available
  String input = Serial.readString(); // read until timeout
  input.trim();                       // remove any \r \n whitespace at the end of the String
  // Serial.println(input);

  // Compare the string using the switch statement
  if (strcmp(input.c_str(), "up") == 0)
  {
    relayToSwitch(upStates);
    Serial.println("KL.15 on & KL.S on");
  }
  else if (strcmp(input.c_str(), "middle") == 0)
  {
    relayToSwitch(middleStates);
    Serial.println("KL.15 off & KL.S on");
  }
  else if (strcmp(input.c_str(), "down") == 0)
  {
    relayToSwitch(downStates);
    Serial.println("KL.15 off & KL.S off");
  }
  else if (strcmp(input.c_str(), "service") == 0)
  {
    relayToSwitch(defaultStates);
    Serial.println("Switch is service mode");
  }
  else
  {
    Serial.println("Invalid command");
  }

  delay(100);
}
#include <Key.h>
#include <Keypad.h>

#include "Waves.h"

const int in1 = 9;


Keypad initKeypad(
  byte rowPin0, byte rowPin1, byte rowPin2, byte rowPin3,
  byte colPin0, byte colPin1, byte colPin2) {
  const byte ROWS = 4;
  const byte COLS = 3;

  char hexaKeys[ROWS][COLS] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'}
  };

  byte rowPins[ROWS] = {rowPin0, rowPin1, rowPin2, rowPin3};
  byte colPins[COLS] = {colPin0, colPin1, colPin2};

  return Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
}


/*
 * Current millisecond in Interval
 * interval: millisecond
 */
int current(int interval) {
  return millis() % interval;
}


void move0() {}

void move1() {}

void move2() {}

void move3() {}


void setup() {
  pinMode(in1, OUTPUT);
}

void loop() {
  static Keypad customKeypad = initKeypad(8, 7, 6, 5, 4, 3, 2);
  static void (* moveFunc[])() = {move0, move1, move2, move3};
  static int move = 0;

  char key = customKeypad.getKey();
  switch (key) 
  {
    case '0':
      move = 0;
      break;

    case '1':
      move = 1;
      break;

    case '2':
      move = 2;
      break;

    case '3':
      move = 3;
      break;

    case '4':
      break;

    case '5':
      break;

    case '6':
      break;

    case '7':
      break;

    default:
      break;
  }

  (* moveFunc[move])();
}

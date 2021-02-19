#include <Key.h>
#include <Keypad.h>

#include "Waves.h"

const int in1 = 9;


/*
 * Initialize keypad.
 * rowPin0~3: Arduino I/O pin number
 * colPin0~2: Arduino I/O pin number
 * Return: keypad instanse.
 */
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
 * Get current millisecond in waveLength.
 * waveLength: millisecond
 * Return: Current millisecond in waveLength.
 */
int current(int waveLength) {
  return millis() % waveLength;
}

/*
 * Waveform output to motor
 */

void move0() {
  analogWrite(in1, 255);
}

void move1() {
  analogWrite(in1, triangleWave(0, 255, 3000, current(3000)));
}

void move2() {}

void move3() {}

void move4() {}

void move5() {}

void move6() {}

void move7() {}


void setup() {
  pinMode(in1, OUTPUT);
}

void loop() {
  static Keypad customKeypad = initKeypad(8, 7, 6, 5, 4, 3, 2);
  static void (* moveFunc[])() = {move0, move1, move2, move3, move4, move5, move6, move7};
  static int move = 0;

  char key = customKeypad.getKey();
  switch (key) 
  {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
      move = key - '0';
      break;

    default:
      break;
  }

  (* moveFunc[move])();
}

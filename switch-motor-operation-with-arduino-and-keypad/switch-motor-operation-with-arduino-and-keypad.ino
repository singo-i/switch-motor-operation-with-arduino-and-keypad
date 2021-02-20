#include <Key.h>
#include <Keypad.h>

#include "Waves.h"

const int in1 = 9;  // Pin number for output to L298N 'IN1'


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
 * Call analogWrite(in1, val)
 */
void analogWriteIn1(int val) {
  analogWrite(in1, val);
}

/*
 * Waveform output to motor
 */

void wave0() {
  analogWriteIn1(255);
}

void wave1() {
  analogWriteIn1(triangleWave(0, 255, 3000, current(3000)));
}

void wave2() {}

void wave3() {}

void wave4() {}

void wave5() {}

void wave6() {}

void wave7() {}


void setup() {
  pinMode(in1, OUTPUT);
}

void loop() {
  static Keypad customKeypad = initKeypad(8, 7, 6, 5, 4, 3, 2);
  static void (* waveFunc[])() = {wave0, wave1, wave2, wave3, wave4, wave5, wave6, wave7};
  static int wave = 0;

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
      wave = key - '0';
      break;

    default:
      break;
  }

  (* waveFunc[wave])();
}

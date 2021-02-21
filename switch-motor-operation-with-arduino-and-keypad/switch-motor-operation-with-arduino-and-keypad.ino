#include <Key.h>
#include <Keypad.h>

#include "Waves.h"

const int in1 = 10;  // Pin number for output to L298N 'IN1'
const int in2 = 9;   // Pin number for output to L298N 'IN1'

const byte ROWS = 4;
const byte COLS = 3;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[ROWS] = {8, 7, 6, 5};  // Pin numbers for keypad
byte colPins[COLS] = {4, 3, 2};     // Pin numbers for keypad


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

long wave0() {
  return 0;
}

long wave1() {
  return triangleWave(0, 255, 3000, current(3000));
}

long wave2() {
  return sawtoothWave(0, 255, 1500, current(1500));
}

long wave3() {
  return negativeSawtoothWave(0, 255, 1500, current(1500));
}

long wave4() {
  return squareWave(0, 255, 2000, current(2000));
}

long wave5() {
  return sineWave(0, 255, 5000, current(5000));
}

long wave6() {
  return cosineWave(0, 255, 5000, current(5000));
}


void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}

void loop() {
  static Keypad keypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
  static long (* waveFunc[])() = {wave0, wave1, wave2, wave3, wave4, wave5, wave6};
  static int wave = 0;

  char key = keypad.getKey();
  switch (key) 
  {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
      wave = key - '0';
      break;
  }

  analogWrite(in1, int((* waveFunc[wave])()));
}

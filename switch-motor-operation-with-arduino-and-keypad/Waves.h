#ifndef _WAVES_h
#define _WAVES_h

#include <Arduino.h>
#include <math.h>  // for M_PI

int triangleWave(int, int, int, int);
int sawtoothWave(int, int, int, int);
int negativeSawtoothWave(int, int, int, int);
int squareWave(int, int, int, int);
int sineWave(int, int, int, int);
int cosineWave(int, int, int, int);

#endif
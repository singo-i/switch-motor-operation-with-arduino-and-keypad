/**
 * @file 
 * @brief Output a waveform
 */
#ifndef _WAVES_h
#define _WAVES_h

#include <Arduino.h>
#include <math.h>  // for M_PI

long triangleWave(long, long, unsigned long, unsigned long);
long sawtoothWave(long, long, unsigned long, unsigned long);
long negativeSawtoothWave(long, long, unsigned long, unsigned long);
long squareWave(long, long, unsigned long, unsigned long);
long sineWave(long, long, unsigned long, unsigned long);
long cosineWave(long, long, unsigned long, unsigned long);

#endif
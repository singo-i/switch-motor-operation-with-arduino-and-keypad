/**
 * @file 
 * @brief Output a waveform
 */
#ifndef _WAVES_h
#define _WAVES_h

#include <Arduino.h>
#include <math.h>  // for M_PI

long triangleWave(long, long, long, long);
long sawtoothWave(long, long, long, long);
long negativeSawtoothWave(long, long, long, long);
long squareWave(long, long, long, long);
long sineWave(long, long, long, long);
long cosineWave(long, long, long, long);

#endif
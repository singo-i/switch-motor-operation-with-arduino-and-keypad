/*
 * 波形を出力
 */

#include "Waves.h"

/*
 * 三角波
 */
int triangleWave(int min_, int max_, int waveLength, int current) {
  if (current * 2 < waveLength) {
    return map(current, 0, waveLength / 2, min_, max_);
  } else {
    return map(current, waveLength / 2, waveLength, max_, min_);
  }
}

/*
 * のこぎり波
 */
int sawtoothWave(int min_, int max_, int waveLength, int current) {
  return map(current, 0, waveLength, min_, max_);
}

/*
 * 逆のこぎり波
 */
int negativeSawtoothWave(int min_, int max_, int waveLength, int current) {
  return map(current, 0, waveLength, max_, min_);
}

/*
 * 矩形波
 */
int squareWave(int min_, int max_, int waveLength, int current) {
  if (current * 2 < waveLength) {
    return max_;
  } else {
    return min_;
  }
}

/*
 * 正弦波
 */
int sineWave(int min_, int max_, int waveLength, int current) {
  return map(sin(2 * M_PI / waveLength * current), -1, 1, min_, max_);
}

int cosineWave(int min_, int max_, int waveLength, int current) {
  return map(cos(2 * M_PI / waveLength * current), -1, 1, min_, max_);
}

/*
 * 波形を出力
 */

#include "Waves.h"

/*
 * 三角波
 */
long triangleWave(long min_, long max_, long waveLength, long current) {
  if (current * 2 < waveLength) {
    return map(current, 0, waveLength / 2, min_, max_);
  } else {
    return map(current, waveLength / 2, waveLength, max_, min_);
  }
}

/*
 * のこぎり波
 */
long sawtoothWave(long min_, long max_, long waveLength, long current) {
  return map(current, 0, waveLength, min_, max_);
}

/*
 * 逆のこぎり波
 */
long negativeSawtoothWave(long min_, long max_, long waveLength, long current) {
  return map(current, 0, waveLength, max_, min_);
}

/*
 * 矩形波
 */
long squareWave(long min_, long max_, long waveLength, long current) {
  if (current * 2 < waveLength) {
    return max_;
  } else {
    return min_;
  }
}

/*
 * 正弦波
 */
long sineWave(long min_, long max_, long waveLength, long current) {
  double wave = sin(2 * M_PI / waveLength * current);
  return map(long(wave * 1000), -1000, 1000, min_, max_);
}

long cosineWave(long min_, long max_, long waveLength, long current) {
  double wave = cos(2 * M_PI / waveLength * current);
  return map(long(wave * 1000), -1000, 1000, min_, max_);
}

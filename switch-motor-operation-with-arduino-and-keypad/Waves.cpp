/*
 * 波形を出力
 */

#include <Arduino.h>
#include <math.h>  // for M_PI

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
 * 正弦波の変位を返す
 * A: 振幅
 * T: 波長
 * t: 時間
 * Returns: 変位（A～-A）
 */
double sineWave(int A, int T, int t) {
  return A * sin(2 * M_PI / T * t);
}

int cosineWave() {}

int tangentWave() {}

/**
 * @file 
 * @brief Output a waveform
 */

#include "Waves.h"

/**
 * @brief Output triangler wave form
 * @param min_: Minimum output
 * @param max_: Maximum output
 * @param waveLength: WaveLength
 * @param current: Current time in wavelength
 * @return Output long integer from min_ to max_.
 * @note The waveform is as follows
 *     +        +     
 *    +++      +++   
 *   +++++    +++++  
 *  +++++++  +++++++ 
 * ++++++++++++++++++
 */
long triangleWave(long min_, long max_, long waveLength, long current) {
  if (current * 2 < waveLength) {
    return map(current, 0, waveLength / 2, min_, max_);
  } else {
    return map(current, waveLength / 2, waveLength, max_, min_);
  }
}

/**
 * @brief Output the sawtooth wave form
 * @param min_: Minimum output
 * @param max_: Maximum output
 * @param waveLength: WaveLength
 * @param current: Current time in wavelength
 * @return Output long integer from min_ to max_.
 * @note The waveform is as follows
 *     +    +     
 *    ++   ++   
 *   +++  +++  
 *  ++++ ++++ 
 * ++++++++++
 */
long sawtoothWave(long min_, long max_, long waveLength, long current) {
  return map(current, 0, waveLength, min_, max_);
}

/**
 * @brief Outputs the waveform of a reverse sawtooth wave
 * @param min_: Minimum output
 * @param max_: Maximum output
 * @param waveLength: WaveLength
 * @param current: Current time in wavelength
 * @return Output long integer from min_ to max_.
 * @note The waveform is as follows
 * +    +     
 * ++   ++   
 * +++  +++  
 * ++++ ++++ 
 * ++++++++++
 */
long negativeSawtoothWave(long min_, long max_, long waveLength, long current) {
  return map(current, 0, waveLength, max_, min_);
}

/**
 * @brief Outputs a square wave form.
 * @param min_: Minimum output
 * @param max_: Maximum output
 * @param waveLength: WaveLength
 * @param current: Current time in wavelength
 * @return Output long integer from min_ to max_.
 * @note The waveform is as follows
 * +++++     +++++           
 * +++++     +++++      
 * +++++     +++++     
 * +++++     +++++     
 * ++++++++++++++++++++
 */
long squareWave(long min_, long max_, long waveLength, long current) {
  if (current * 2 < waveLength) {
    return max_;
  } else {
    return min_;
  }
}

/**
 * @brief Outputs a sine wave form.
 * @param min_: Minimum output
 * @param max_: Maximum output
 * @param waveLength: WaveLength
 * @param current: Current time in wavelength
 * @return Output long integer from min_ to max_.
 * @note The waveform is as follows
 *           ++++                    ++++          
 *        ++++++++++              ++++++++++       
 *      ++++++++++++++          ++++++++++++++     
 *    ++++++++++++++++++      ++++++++++++++++++   
 * ++++++++++++++++++++++++++++++++++++++++++++++++
 */
long sineWave(long min_, long max_, long waveLength, long current) {
  double wave = sin(2 * M_PI / waveLength * current);
  return map(long(wave * 1000), -1000, 1000, min_, max_);
}

/**
 * @brief Outputs a cosine wave form.
 * @param min_: Minimum output
 * @param max_: Maximum output
 * @param waveLength: WaveLength
 * @param current: Current time in wavelength
 * @return Output long integer from min_ to max_.
 * @note The waveform is as follows
 * ++                    ++++                    ++
 * +++++              ++++++++++              +++++
 * +++++++          ++++++++++++++          +++++++
 * +++++++++      ++++++++++++++++++      +++++++++
 * ++++++++++++++++++++++++++++++++++++++++++++++++
 */
long cosineWave(long min_, long max_, long waveLength, long current) {
  double wave = cos(2 * M_PI / waveLength * current);
  return map(long(wave * 1000), -1000, 1000, min_, max_);
}

#ifndef PLAYSBADLYWITHOTHERS_H
#define PLAYSBADLYWITHOTHERS_H
#include <iostream>
#include <string>
#include <random>
#include <chrono>

/**
 * The PlaysBadlyWithOthers object provides a parameterized counting function for threads.
 *
 * The constructor is default (there are no parameters) and the run() method takes
 * a starting, ending, and stride value, counting the range [start, end) by stride.
 * The separating string between printed values is an optional parameter.
 *
 * Note that this is designed as a very simple class that provides the
 * run() member function for use a a std::thread execution function.
 */
class PlaysBadlyWithOthers {
  public:
  PlaysBadlyWithOthers() = default;

  /**
   * Count [start, end) by stride, printing each value with spacer between.
   *
   * Prints spacer and then the count for each value generated.
   * @param counter reference to the counter that should be incremented
   * @param numberOfTimesToIncrement the number of times to increment the counter
   * @note Designed to be called as a thread's execution function.
   */
  void run(int & counter, int numberOfTimesToIncrement) {
    for (auto i = 0; i < numberOfTimesToIncrement; i++) {
      counter++;
    }
  }
};
#endif /* PLAYSBADLYWITHOTHERS_H */

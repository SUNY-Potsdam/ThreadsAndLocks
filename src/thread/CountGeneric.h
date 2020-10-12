#ifndef COUNTGENERIC_H
#define COUNTGENERIC_H
#include <iostream>
#include <string>
#include <random>
#include <chrono>

/**
 * The CountGeneric object provides a parameterized counting function for threads.
 *
 * The constructor is default (there are no parameters) and the run() method takes
 * a starting, ending, and stride value, counting the range [start, end) by stride.
 * The separating string between printed values is an optional parameter.
 *
 * Note that this is designed as a very simple class that provides the
 * run() member function for use a a std::thread execution function.
 */
class CountGeneric {
  public:
  CountGeneric() = default;

  /**
   * Count [start, end) by stride, printing each value with spacer between.
   *
   * Prints spacer and then the count for each value generated.
   * @param start where the count begins; inclusive
   * @param end where the count ends; exclusive
   * @param stride value to count by; should not be 0 or loop never ends
   * @param spacer string to print between values generated in the loop
   * @note Designed to be called as a thread's execution function.
   */
  void run(int start, int end, int stride,
           const std::string & spacer) {
    // Seed with a real random value, if available
    std::random_device r;

    // Choose a random mean between 1 and 6
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(100, 250);
    int waitToStart = uniform_dist(e1);

    std::cout << "start " << start << " sleeps for " << waitToStart << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(waitToStart));


    int generatedSoFar = 0;
    for (auto i = start; i < end; i += stride,generatedSoFar++) {
      std::cout << spacer << i;

      if ((generatedSoFar + 1) % 256 == 0) { // pause every once in a while
         waitToStart = uniform_dist(e1);
         std::this_thread::sleep_for(std::chrono::milliseconds(waitToStart));
      }

    }
    std::cout << std::endl;
  }
};
#endif /* COUNTGENERIC_H */

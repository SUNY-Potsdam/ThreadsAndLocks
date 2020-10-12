#ifndef COUNTEVENS_H
#define COUNTEVENS_H
#include <iostream>
#include <string>

/**
 * The CountEven class counts from 0 to max by twos.
 *
 * It stops as soon as the count is greater than or equal to max and
 * it prints out each number to stdout as it is counted. The
 * constructor takes as parameters the value of max and, optionally, a
 * string to print between values printed in the run() method.
 *
 * Note that this is designed as a very simple class that provides the
 * run() member function for use a a std::thread execution function.
 */
class CountEvens {
  public:
  /**
   * Constructor for an object that counts by 2 to the given max.
   *
   * @param max the number to stop counting on; count is up to but not including max.
   * @param space [default = " "] the string to print between values as they are counted.
   */
  CountEvens(int max, const std::string & space = " ") :
    maxCount{max}, spacer{space} {
    // nothing to do
  }
  /**
   * Count from 0 to this->max by twos (by even numbers)
   *
   * Prints each value as it is generated.
   * @note Designed to be called as a thread's execution function.
   */
  void run() {
    for (auto i = 0; i < maxCount; i += 2) {
      std::cout << spacer << i;
    }
    std::cout << std::endl;
  }
  private:
  // the number to count up to but not include
  int maxCount;
  // the spacing string printed between generated values.
  std::string spacer;
};
#endif /* COUNTEVENS_H */

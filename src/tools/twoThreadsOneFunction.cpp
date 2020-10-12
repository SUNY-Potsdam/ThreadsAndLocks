#include <iostream>
#include <thread>
#include "CountGeneric.h"

using namespace std;

/* constexpr sets the variable to be CONSTANT (cannot be assigned to) AND sets
   its value so that it could be used at compile time. */
constexpr int COUNT_MAX = 10000;

/**
 * Start two threads, each running CountGeneric::run with different parameters.
 * Notice that the first parameter after the member function pointer is the object
 * on which the member function is to run. Remaining parameters for the thread's
 * payload function follow. They must be movable values.
 *
 * Note that with main running, too, there are actually THREE threads running.
 */
int main() {
  // evens starts at 0; uses * between values for visual differentiation
  thread evens(&CountGeneric::run, CountGeneric(), 0, COUNT_MAX, 2, "*");
  // odds starts at 1; uses - between values for visual differentiation
  thread odds(&CountGeneric::run, CountGeneric(), 1, COUNT_MAX, 2, "-");
  cout << "main() waiting" << endl;
  evens.join();
  odds.join();
  return 0;
}

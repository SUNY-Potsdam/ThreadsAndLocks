#include <iostream>
#include <thread>
#include "CountEvens.h"
#include "CountOdds.h"

using namespace std;

/* constexpr sets the variable to be CONSTANT (cannot be assigned to) AND sets
   its value so that it could be used at compile time. */
constexpr int COUNT_MAX = 10000;

/* The standard "payload" of a thread is a thread function: a void
 * function with no parameters. This program has two thread functions,
 * count_evens and count_odds. Each uses only function-local writable
 * variables so there is no interference between them in memory. Since
 * they share the output stream, however, there can be interference
 * there. */

/**
 * The main program: create (and, implicitly start) a thread around
 * each of the thread functions defined above. This means there are
 * actually THREE threads running.
 *
 * The join operations could be a problem since the order in which the
 * thread functions terminate is unknown ahead of times.
 */
int main() {
  thread evens(&CountEvens::run, CountEvens(COUNT_MAX));
  thread odds(&CountOdds::run, CountOdds(COUNT_MAX));
  cout << "main() waits to join even and odd threads." << endl;
  evens.join();
  odds.join();
  cout << "main() joined by both threads; terminating." << endl;
  return 0;
}

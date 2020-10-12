#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <functional>
#include "PlaysBadlyWithOthers.h"
using namespace std;


/**
 * The main program: create (and, implicitly start) threads around the one
 * thread function. The thread function modifies the global variable from
 * multiple threads.
 */
int main(int argc, char * argv[]) {
  int counter = 0;
  vector<string> arguments; // command-line arguments translated to strings
  for (int aNdx = 0; aNdx < argc; ++aNdx)
    arguments.push_back(argv[aNdx]);

  int thread_count = (arguments.size() > 1)?stoi(arguments[1]):3;
  int times_to_increment = (arguments.size() > 2)?stoi(arguments[2]):1000;

  // the typedef makes the array declaration easier to read.
  typedef thread * thread_ptr;

  thread_ptr * threads = new thread_ptr[thread_count];

  // create (and start) the threads
  for (int i = 0; i < thread_count; ++i)
    threads[i] = new thread(&PlaysBadlyWithOthers::run, PlaysBadlyWithOthers(), ref(counter), times_to_increment);


  // wait for each of the threads to finish and, when one does, clean up
  for (int i = 0; i < thread_count; ++i) {
    threads[i]->join();
    delete threads[i];
  }
  // free the memory allocated to the array
  delete[] threads;

  // results: the number of times the variable SHOULD have been incremented
  // and the actual value the variable has
  cout << "expected: " << thread_count * times_to_increment << endl;
  cout << "     got: " << counter << endl;

  return 0;
}

#include <iostream>
#include <thread>
#include <string>
#include <vector>

using namespace std;

/**
 * Modify the modifiable string into the target string value, delaying using
 * only a for-loop (to explicit call to sleep or usleep); the length of the
 * delay is controlled by the last parameter.
 *
 * @param string_to_modify string reference; characters will be
 *        changed one at a time. Must be same length as target_string
 * @param target_string string to change the modify string into.
 *        Must be the same length as string_to_modify.
 * @param per_character_loop_delay number of loops to delay as each
 *        character value is set into a character in string_to_modify
 */
void warp(string & string_to_modify, const string & target_string,
          int per_character_loop_delay) {
  for (unsigned int c = 0; c < string_to_modify.length(); ++c) {
    for (int a = 'a'; a <= 'z'; ++a) {
      for (int i = 0; i < per_character_loop_delay; ++i)
        string_to_modify[c] = a;
    }
    string_to_modify[c] = target_string[c];
  }
}

/**
 * The main program: create (and, implicitly start) a thread around
 * the thread function defined above.
 */
int main(int argc, char * argv[]) {
  vector<string> arguments; // command-line arguments translated to strings
  for (int aNdx = 0; aNdx < argc; ++aNdx)
    arguments.push_back(argv[aNdx]);

  int delayLoop = (arguments.size() > 1)?stoi(arguments[1]):1000;
  string start_string = (arguments.size() > 2)?arguments[2]:"INITIAL";
  string stop_string = (arguments.size() > 3)?arguments[3]:"FINAL";

  /****************************************************************************/
  // Make sure starting and finishing strings are the same length. Set
  // reference to longer and shorter strings and pad shorter with spaces
  // until lengths match.
  string & shorter = (start_string.length()<stop_string.length())?start_string:stop_string;
  string & longer = (start_string.length()>=stop_string.length())?start_string:stop_string;

  while (shorter.length() < longer.length())
    shorter += " ";
  /****************************************************************************/

  // spin up the thread that modifies the string
  thread transform(&warp, ref(start_string), stop_string, delayLoop);

  // wait until the string is completely modified, printing out the intermediate
  // changes by following the string with just a "carriage return" to send the
  // cursor back to the beginning of the line
  while (start_string != stop_string) {
    cout << start_string << '\r';
    cout.flush(); // flush pending changes
  }

  // make sure finished string is printed and advance to next line
  cout << start_string << endl;

  // Probably unnecessary since the thread finished changing
  // the string before while loop terminated
  transform.join();
  return 0;
}

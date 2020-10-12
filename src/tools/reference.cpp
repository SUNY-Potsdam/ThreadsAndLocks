// thread example
#include <iostream> // std::cout
#include <thread>   // std::thread
#include <chrono>

using namespace std;
void foo() {
  for (int i = 0; i < 100; ++i) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    cout << "foo()" << endl;
  }

}

void bar(int x) {
  for (int i = 0; i < 100; ++i) {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    cout << "bar(" << x << ")" << endl;
  }

}

int main() {
  std::thread first(foo);     // spawn new thread that calls foo()
  std::thread second(bar, 0); // spawn new thread that calls bar(0)

  std::cout << "main, foo and bar now execute concurrently...\n";

  // synchronize threads:
  if (first.joinable()) first.join();  // pauses until first finishes
  if (second.joinable()) second.join(); // pauses until second finishes

  std::cout << "foo and bar completed.\n";

  return 0;
}

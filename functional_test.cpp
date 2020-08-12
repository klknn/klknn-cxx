#include <assert.h>
#include <iostream>
#include "functional.hpp"


using klknn::functional::FPtr;

int add(int x) { return x + 1; }

int main() {
  // simple fptr
  FPtr f2 = add;
  assert(f2(2) == 3);

  constexpr int z = 1;
  auto ladd = [](int x) { return x + z; };
  // TODO: deduction guide?
  FPtr<int(int)> f3 = ladd;
  assert(f3(2) == 3);

  std::cout << "OK" << std::endl;
}

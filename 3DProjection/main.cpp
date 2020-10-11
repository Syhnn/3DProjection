#include <iostream>

#include "Core.hpp"
#include "Errors.hpp"


using namespace std;


int main(int argc, char* argv[]) {
  Core c;

  if (!c.init()) return errors::exit_core_init;

  c.mainloop();

  return errors::exit_success;
}
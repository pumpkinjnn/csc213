#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

// This line defines a new type, fn_t, that is a function that takes no arguments.
// Function pointer syntax in C is scary, but the rest of it works a lot like Scheme.
typedef void (*fn_t)();

// Declaration of the every function, which calls `fn` every `interval` milliseconds `num_runs` times.
void every(size_t num_runs, size_t interval, fn_t fn);

// You may be a little alarmed to see the type `size_t`. This is just an integer of some sort, defined to be the "right" width (number of bits) to count things on the current machine. This type and many others like it are defined in stdint.h.

// This is a function that will be called at some regular interval
void some_action() {
  printf("Here I am!\n");
}

int main(int argc, char** argv) {
  // Use `every` to invoke `some_action` five times, once per second.
  every(5, 2500, some_action);
  return 0;
}

void every(size_t num_runs, size_t interval, fn_t fn) {
  //Initalize timespec
  struct timespec sleep_time;
  sleep_time.tv_sec = interval/1000;
  sleep_time.tv_nsec = (interval%1000)*1000000;
  
  //First call immediately
  fn();

  //Subsequent calls
  for(int i = 1; i < num_runs; i++) {
     if(nanosleep(&sleep_time, NULL) < 0){
       printf("Nanosleep system call failed!\n");
     }
     fn();
  }
}

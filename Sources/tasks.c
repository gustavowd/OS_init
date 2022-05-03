#include "os.h"

void task1(void) {
  int i = 0;
  for(;;){
    i++;
    yield();
  }
}

void task2(void) {
  int i = 0;
  for(;;){
    i++;
    yield();
   }
}

void task3(void) {
  int i = 0;
  for(;;){
    i++;
    yield();

  }
}


void task4(void) {
  int i = 0;
  for(;;){
    i++;
    yield();
  }
}

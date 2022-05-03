#include "os.h"
#include <stdlib.h>

volatile TCB_t TCB[4];
cpu_t idle_stk[128];

volatile cpu_t ct = 0;
volatile cpu_t it = 0;
volatile long long os_time = 0;


void idle(void) {
  for(;;){
    // dorme aqui
  }
}


void start_os(void){
  InstallTask(idle, 0, idle_stk, sizeof(idle_stk));
  init_os_timer();
  
  stk_tmp = TCB[0].stk;
  dispatcher();
}


void delay(long long timeout){

}


cpu_t os_inc_and_compare(void){

}


void InstallTask(task_t task, cpu_t prio, cpu_t *stk, int stk_size){
  TCB[it].stk = PrepareStack(task, stk, stk_size);
  TCB[it].prio = prio;
  TCB[it].ready = 1;
  it++;
}



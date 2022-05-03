#include "port.h"


#define null (void*)0

typedef void (*task_t)(void); 

struct _TCB{
  cpu_t *stk;
  cpu_t prio;
  cpu_t ready;
};

typedef struct _TCB TCB_t;


extern volatile TCB_t TCB[4];
extern volatile cpu_t ct;
extern volatile cpu_t it;
extern TCB_t *current_task;

void InstallTask(task_t task, cpu_t prio, cpu_t *stk, int stk_size); 

void delay(long long timeout);
void start_os(void);
cpu_t os_inc_and_compare(void);
cpu_t *scheduler(void);



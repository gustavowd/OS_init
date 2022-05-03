#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "os.h"
#include "tasks.h"

#ifdef __cplusplus
 extern "C"
#endif
void MCU_init(void); /* Device initialization function declaration */
                                

cpu_t stk1[128];
cpu_t stk2[128];
cpu_t stk3[128];

void main(void) {
  MCU_init(); /* call Device Initialization */   

  /* include your code here */
  InstallTask(task1, 1, stk1, sizeof(stk1));
  InstallTask(task2, 2, stk2, sizeof(stk2));
  InstallTask(task3, 3, stk3, sizeof(stk3));
  
  stk_tmp = TCB[0].stk;
  dispatcher();

  for(;;) {
    /* __RESET_WATCHDOG(); by default, COP is disabled with device init. When enabling, also reset the watchdog. */
  } /* loop forever */
  /* please make sure that you never leave main */
}

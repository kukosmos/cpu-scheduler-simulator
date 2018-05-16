#ifndef __EVALUATE_H
#define __EVALUATE_H

#include "process.h"

/* evaluate turn around time for n processes
 * by calculate termination time - arrival time
 * return average turn around time
 * process' turn around time will be stored in return_list
 * return_list SHOULD have n + 1 space for n processes
 */
double evaluate_turn_around_time (int n, process_t ** process_list, int * return_list);

/* evaluate waiting time for n processes
 * by calculate termination time - arrival time - cpu & io burst time
 * return average waiting time
 * process' waiting time whill be stored in return_list
 * return_list SHOULD have n + 1 space for n processes
 */
double evaluate_waiting_time (int n, process_t ** process_list, int * return_list);

/* print with form
 */
void print_list (char * desc, int n, int * list);

#endif

#ifndef __EVALUATE_H
#define __EVALUATE_H

#include "process.h"

/* evaluate turn around time
 * by calculate termination time - arrival time
 * return average turn around time
 * process' turn around time will be stored in return_list
 */
double evaluate_turn_around_time (int n, process_t * process_list, double * return_list);

/* evaluate waiting time
 * by calculate termination time - arrival time - cpu & io burst time
 * return average waiting time
 * process' waiting time whill be stored in return_list
 */
double evaluate_waiting_time (int n, process_t * process_list, double * return_list);

/* print with form
 */
void print_list (char * desc, int n, double * list);

#endif

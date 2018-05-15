#ifndef __NP_SJF_H
#define __NP_SJF_H

#include "../cpu_scheduler.h"
#include "../process.h"

/* non-preemptive SJF queue is priority queue
 * shorter cpu burst time, higher priority
 */
void * create_np_sjf_queue ();

/* function for cpu scheduling
 */
void np_sjf_scheduling (cpu_scheduler_t * cpu_scheduler);

/* np-SJF enqueue
 */
void np_sjf_enqueue (void * queue, process_t * process);

#endif

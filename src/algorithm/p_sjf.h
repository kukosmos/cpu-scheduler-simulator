#ifndef __P_SFJ_H
#define __P_SFJ_H

#include "../cpu_scheduler.h"
#include "../process.h"

/* preemptive SJF queue is priority queue
 * shorter cpu burst time, higher priority
 */
void * create_p_sjf_queue ();

/* function for cpu scheduling
 * support preemption
 */
void p_sjf_scheduling (cpu_scheduler_t * cpu_scheduler);

/* p-SJF enqueue
 */
void p_sjf_enqueue (void * queue, process_t * process);

#endif

#ifndef __P_PRIORITY_H
#define __P_PRIORITY_H

#include "../cpu_scheduler.h"
#include "../process.h"

/* preemptive priority queue is priority queue
 * smaller priority value, higher priority
 */
void * create_p_priority_queue ();

/* function for cpu scheduling
 * support preemption
 */
void p_priority_scheduling (cpu_scheduler_t * cpu_scheduler);

/* p-priority enqueue
 */
void p_priority_enqueue (void * queue, process_t * process);

#endif

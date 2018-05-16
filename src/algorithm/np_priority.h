#ifndef __NP_PRIORITY_H
#define __NP_PRIORITY_H

#include "../cpu_scheduler.h"
#include "../process.h"

/* non-preemptive priority queue is priority queue
 * smaller priority value, higher priority
 */
void * create_np_priority_queue ();

/* function for cpu scheduling
 */
void np_priority_scheduling (cpu_scheduler_t * cpu_scheduler);

/* np-priority enqueue
 */
void np_priority_enqueue (void * queue, process_t * process);

#endif

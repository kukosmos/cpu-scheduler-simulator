#ifndef __FCFS_H
#define __FCFS_H

#include "../process.h"
#include "../cpu_scheduler.h"

/* FCFS queue is FIFO queue
 */
void * create_fcfs_queue ();

/* pthread function for cpu scheduler
 */
void fcfs_scheduling (CPU_scheduler * cpu_scheduler);

/* enqueue
 */
void fcfs_enqueue (void * queue, Process * process);

#endif

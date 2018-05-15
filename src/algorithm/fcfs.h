#ifndef __FCFS_H
#define __FCFS_H

#include "../process.h"
#include "../cpu_scheduler.h"

/* FCFS queue is FIFO queue
 */
void * create_fcfs_queue ();

/* function for cpu scheduling
 */
void fcfs_scheduling (cpu_scheduler_t * cpu_scheduler);

/* FCFS enqueue
 */
void fcfs_enqueue (void * queue, process_t * process);

#endif

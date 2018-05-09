#ifndef __FCFS_H
#define __FCFS_H

#include "../process.h"

/* FCFS queue is FIFO queue
 */
void * create_fcfs_queue ();

/* pthread function for cpu scheduler
 */
void * fcfs_scheduling (void * cpu_scheduler);

/* enqueue
 */
void fcfs_enqueue (void * queue, Process * process);

#endif

#ifndef __FCFS_H
#define __FCFS_H

#include "../process.h"

void * create_fcfs_queue ();

void * fcfs_scheduling (void * cpu_scheduler);

void fcfs_enqueue (void * queue, Process * process);

#endif

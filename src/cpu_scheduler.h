#ifndef __CPU_SCHEDULER_H
#define __CPU_SCHEDULER_H

#include <pthread.h>

#include "clock.h"
#include "process.h"
#include "cpu.h"

struct __cpu_scheduler {
    char * algo;
    int state;
    Clock * clk;
    void * queue;
    CPU * cpu;
    void (* enqueue) (void * queue, Process * process);
    void * (* scheduling) (void * arg);
    pthread_t tid;
};

// due to cyclic inclustion
#ifndef __DEF_TYPE_CPU_SCHEDULER
#define __DEF_TYPE_CPU_SCHEDULER
typedef struct __cpu_scheduler CPU_scheduler;
#endif

/* create cpu scheduler
 * with algorithm 'algo'
 * simulator support
 * 1. FCFS (fcfs)
 * 2. Non-preemptive SJF (np_sjf)
 * 3. Preemptive SJF (p_sjf)
 * 4. Non-preemptive Priority (np_priority)
 * 5. Preemptive Priority (p_priority)
 * 6. Round Robin (rr)
 */
CPU_scheduler * create_cpu_scheduler (char * algorithm, Clock * clock);

/* delete cpu scheduler
 */
void delete_cpu_scheduler (CPU_scheduler * cpu_scheduler);

/* register cpu
 */
void register_cpu (CPU_scheduler * cpu_scheduler, CPU * cpu);

/* add new process to queue
 */
void new_process (CPU_scheduler * cpu_scheduler, Process * process);

/* start cpu scheduling
 */
void start_cpu_scheduling (CPU_scheduler * cpu_scheduler);

/* stop cpu scheduling
 */
void stop_cpu_scheduling (CPU_scheduler * cpu_scheduler);

#endif

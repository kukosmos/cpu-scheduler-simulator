#ifndef __CPU_SCHEDULER_H
#define __CPU_SCHEDULER_H

#include "clock.h"
#include "process.h"
#include "cpu.h"

struct __cpu_scheduler {
    char * algo;
    clk_t * clk;
    void * queue;
    cpu_t * cpu;
    void (* enqueue) (void * queue, process_t * process);
    void (* scheduling) (struct __cpu_scheduler * cpu_scheduler);
};

// due to cyclic inclustion
#ifndef __DEF_TYPE_CPU_SCHEDULER
#define __DEF_TYPE_CPU_SCHEDULER
typedef struct __cpu_scheduler cpu_scheduler_t;
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
cpu_scheduler_t * create_cpu_scheduler (char * algorithm, clk_t * clock, ...);

/* delete cpu scheduler
 */
void delete_cpu_scheduler (cpu_scheduler_t * cpu_scheduler);

/* register cpu
 */
void register_cpu (cpu_scheduler_t * cpu_scheduler, cpu_t * cpu);

/* add new process to queue
 */
void new_process (cpu_scheduler_t * cpu_scheduler, process_t * process);

#endif

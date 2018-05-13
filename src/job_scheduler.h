#ifndef __JOB_SCHEDULER_H
#define __JOB_SCHEDULER_H

#include "process.h"
#include "clock.h"
#include "cpu_scheduler.h"

struct __js_queue_node {
    process_t * p;
    struct __js_queue_node * next;
};

/* priority queue
 * order by arrival time
 */
struct __js_queue {
    struct __js_queue_node * front;
    struct __js_queue_node * head;
};

struct __job_scheduler {
    struct __js_queue * queue;
    clk_t * clk;
    cpu_scheduler_t * cs;
};

typedef struct __job_scheduler job_scheduler_t;

/* create job scheduler
 */
job_scheduler_t * create_job_scheduler (clk_t * clock);

/* delete job scheduler
 */
void delete_job_scheduler (job_scheduler_t * job_scheduler);

/* register cpu scheduler to job scheduler
 */
void js_register_cpu_scheduler (job_scheduler_t * job_scheduler, cpu_scheduler_t * cpu_scheduler);

/* create n processes
 */
void create_processes (job_scheduler_t * job_scheduler, int n);

/* do scheduling for one clock cycle
 * give cpu a process which its arrival time = clock time
 */
void job_scheduling (job_scheduler_t * job_scheduler);

/* restart job scheduling with existing process queue
 */
void reset_job_scheduling (job_scheduler_t * job_scheduler);

/* print processes informations to schedule
 */
void print_processes (job_scheduler_t * job_scheduler);

/* return TRUE if all processes' remain time is 0
 */
int all_terminated (job_scheduler_t * job_scheduler);

#endif

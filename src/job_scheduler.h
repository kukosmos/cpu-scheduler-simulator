#ifndef __JOB_SCHEDULER_H
#define __JOB_SCHEDULER_H

#include <pthread.h>

#include "process.h"
#include "clock.h"
#include "cpu_scheduler.h"

struct __js_queue_node {
    Process * p;
    struct __js_queue_node * next;
};

/* priority queue
 * order by arrival time
 */
struct __js_queue {
    struct __js_queue_node * front;
    struct __js_queue_node * head;
};

typedef struct __js_queue JS_queue;

struct __job_scheduler {
    JS_queue * queue;
    Clock * clk;
    CPU_scheduler * cs;
    pthread_t tid;
};

typedef struct __job_scheduler Job_scheduler;

/* create job scheduler
 */
Job_scheduler * create_job_scheduler (Clock * clock);

/* delete job scheduler
 */
void delete_job_scheduler (Job_scheduler * job_scheduler);

/* register cpu scheduler to job scheduler
 */
void register_cpu_scheduler (Job_scheduler * job_scheduler, CPU_scheduler * cpu_scheduler);

/* create n processes
 */
void create_processes (Job_scheduler * job_scheduler, int n);

/* start job scheduling
 */
void start_job_scheduling (Job_scheduler * job_scheduler);

/* stop job scheduling
 * even if there are some processes left in queue
 */
void stop_job_scheduling (Job_scheduler * job_scheduler);

/* restart job scheduling with existing process queue
 */
void reset_job_scheduling (Job_scheduler * job_scheduler);

/* print processes informations to schedule
 */
void print_processes (Job_scheduler * job_scheduler);

#endif

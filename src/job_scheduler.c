#include <stdio.h>
#include <stdlib.h>

#include "job_scheduler.h"

#define NODE struct __js_queue_node
#define QUEUE struct __js_queue

#define TRUE 1
#define FALSE 0

void delete_nodes (NODE * node) {
    if (node->next != NULL) {
        delete_nodes (node->next);
    }
    free (node);
}

void delete_queue (QUEUE * queue) {
    if (queue->front != NULL) {
        delete_nodes (queue->front);
    }
    free (queue);
}

/* insert new process node
 * order by arrival time of process
 */
void js_enqueue (QUEUE * queue, process_t * p) {
    NODE * node = (NODE *) malloc (sizeof (NODE));
    
    node->p = p;
    node->next = NULL;

    if (queue->front == NULL) {
        queue->front = node;
    } else {
        NODE * t = queue->front;
        NODE * bf = NULL;
        while (t != NULL && t->p->arrival_time <= p->arrival_time) {
            bf = t;
            t = t->next;
        }
        if (bf == NULL) {
            node->next = t;
            queue->front = node;
        } else {
            node->next = t;
            bf->next = node;
        }
    }
}

/* delete process from front
 * NOT free nodes
 */
process_t * js_dequeue (QUEUE * queue) {
    NODE * t = queue->head;
    queue->head = queue->head->next;

    return t->p;
}

/* return TRUE when queue is empty
 * BUT queue MAY NEED DEALLOCATION
 * because dequeue don't free nodes
 */
int js_queue_is_empty (QUEUE * queue) {
    return queue->head == NULL;
}

/* return arrival time of first process in queue
 */
int js_first_arrival_time (QUEUE * queue) {
    return queue->head->p->arrival_time;
}

/* give cpu scheduler new process when clock = arrival time
 */
void job_scheduling (job_scheduler_t * this) {
    while (!js_queue_is_empty (this->queue) && js_first_arrival_time (this->queue) == get_time (this->clk)) {
        process_t * proc = js_dequeue (this->queue);
        new_process (this->cs, proc);
    }
}

job_scheduler_t * create_job_scheduler (clk_t * clk) {
    job_scheduler_t * js = (job_scheduler_t *) malloc (sizeof (job_scheduler_t));
    
    js->queue = (QUEUE *) malloc (sizeof (QUEUE));;
    js->clk = clk;
    js->cs = NULL;

    return js;
}

/* free all the allocated memory
 */
void delete_job_scheduler (job_scheduler_t * this) {
    delete_queue (this->queue);
    free (this);
}

void js_register_cpu_scheduler (job_scheduler_t * this, cpu_scheduler_t * cs) {
    this->cs = cs;
}

void create_processes (job_scheduler_t * this, int n) {
    if (this->queue->front != NULL) {
        delete_nodes (this->queue->front);
    }
    for (int i = 1; i <= n; i++) {
        process_t * p = create_process (i);
        js_enqueue (this->queue, p);
    }
    this->queue->head = this->queue->front;
}

void reset_job_scheduling (job_scheduler_t * this) {
    this->queue->head = this->queue->front;
    NODE * t = this->queue->head;
    while (t != NULL) {
        t->p->cpu_remain_time = t->p->cpu_burst_time;
        t->p->io_remain_time = t->p->io_burst_time;
        t->p->termination_time = 0;
        t = t->next;
    }
}

void print_processes (job_scheduler_t * this) {
    NODE * t = this->queue->front;

    printf ("+-----+--------------+----------------+---------------+---------------+----------+\n");
    printf ("| pid | arrival_time | cpu_burst_time | io_start_time | io_burst_time | priority |\n");
    printf ("+-----+--------------+----------------+---------------+---------------+----------+\n");

    while (t != NULL) {
        process_t * p = t->p;
        printf ("| %3u | %12u | %14u | %13u | %13u | %8u |\n", p->pid, p->arrival_time, p->cpu_burst_time, p->io_start_time, p->io_burst_time, p->priority);
        printf ("+-----+--------------+----------------+---------------+---------------+----------+\n");
        t = t->next;
    }
    printf ("\n");
}

int all_terminated (job_scheduler_t * this) {
    int result = TRUE;
    NODE * n = this->queue->front;
    while (n != NULL) {
        if (n->p->cpu_remain_time != 0) {
            result = FALSE;
            break;
        }
        n = n->next;
    }
    return result;
}

void get_processes (job_scheduler_t * this, process_t ** pl) {
    NODE * t = this->queue->front;
    while (t != NULL) {
        pl [t->p->pid] = t->p;
        t = t->next;
    }
}
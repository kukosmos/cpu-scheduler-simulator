#include <stdlib.h>

#include "rr.h"

#define QUEUE struct __rr_queue
#define NODE struct __rr_node

struct __rr_node {
    process_t * p;
    struct __rr_node * next;
};

/* queue hold remain time quantum value
 */
struct __rr_queue {
    unsigned int time_quantum;
    unsigned int remain;
    struct __rr_node * head;
    struct __rr_node * tail;
};

process_t * rr_dequeue (QUEUE * queue) {
    NODE * del = queue->head;
    queue->head = del->next;
    process_t * p = del->p;
    free (del);
    return p;
}

int rr_is_empty (QUEUE * queue) {
    return queue->head == NULL;
}

void * create_rr_queue (int tq) {
    QUEUE * queue = (QUEUE *) malloc (sizeof (QUEUE));
    queue->time_quantum = tq;
    queue->remain = 0;
    queue->head = NULL;
    queue->tail = NULL;
    return (void *) queue;
}

void rr_scheduling (cpu_scheduler_t * this) {
    if (rr_is_empty ((QUEUE *) this->queue) && !is_running (this->cpu)) {
        // if queue is empty and cpu is idle
        return;
    }
    if (rr_is_empty ((QUEUE *) this->queue) && ((QUEUE *) this->queue)->remain == 0) {
        // if queue is empty but process consumed all the time quantum
        ((QUEUE *) this->queue)->remain = ((QUEUE *) this->queue)->time_quantum - 1;    // reset remain time quantum
        return;
    }
    if (is_running (this->cpu) && ((QUEUE *) this->queue)->remain > 0) {
        // if time previous process do not consum all time quantum
        ((QUEUE *) this->queue)->remain = ((QUEUE *) this->queue)->remain - 1;
        return;
    }
    process_t * orig;
    execute (this->cpu, rr_dequeue ((QUEUE *) this->queue), &orig);
    if (orig != NULL) {
        // if preempted due to consuming all time quantum
        rr_enqueue (this->queue, orig);
    }
    ((QUEUE *) this->queue)->remain = ((QUEUE *) this->queue)->time_quantum - 1;    // reset remain time quantum
}

void rr_enqueue (void * arg, process_t * process) {
    QUEUE * queue = (QUEUE *) arg;
    NODE * node = (NODE *) malloc (sizeof (NODE));
    node->p = process;
    node->next = NULL;
    if (queue->head == NULL) {
        queue->head = node;
        queue->tail = node;
    } else {
        queue->tail->next = node;
        queue->tail = node;
    }
}
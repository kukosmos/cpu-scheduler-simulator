#include <stdlib.h>

#include "sjf.h"

#define NODE struct __sjf_node
#define QUEUE struct __sjf_queue

QUEUE * create_sjf_queue () {
    QUEUE * queue = (QUEUE *) malloc (sizeof (QUEUE));
    queue->head = NULL;
    return queue;
}

void sjf_enqueue (QUEUE * queue, process_t * process) {
    NODE * node = (NODE *) malloc (sizeof (NODE));
    node->p = process;
    node->next = NULL;

    NODE * t = queue->head;
    NODE * bf = NULL;
    while (t != NULL && t->p->cpu_burst_time <= process->cpu_burst_time) {
        bf = t;
        t = t->next;
    }
    node->next = t;
    if (bf == NULL) {
        node->next = queue->head;
        queue->head = node;
    } else {
        bf->next = node;
    }
}

process_t * sjf_dequeue (QUEUE * queue) {
    NODE * del = queue->head;
    process_t * r = del->p;
    queue->head = del->next;
    free (del);
    return r;
}

int sjf_is_empty (QUEUE * queue) {
    return queue->head == NULL;
}
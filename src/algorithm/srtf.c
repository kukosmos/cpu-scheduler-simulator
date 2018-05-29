#include <stdlib.h>

#include "srtf.h"

#define NODE struct __srtf_node
#define QUEUE struct __srtf_queue

QUEUE * create_srtf_queue () {
    QUEUE * queue = (QUEUE *) malloc (sizeof (QUEUE));
    queue->head = NULL;
    return queue;
}

void srtf_enqueue (QUEUE * queue, process_t * process) {
    NODE * node = (NODE *) malloc (sizeof (NODE));
    node->p = process;
    node->next = NULL;

    NODE * t = queue->head;
    NODE * bf = NULL;
    while (t != NULL && t->p->cpu_remain_time <= process->cpu_remain_time) {
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

process_t * srtf_dequeue (QUEUE * queue) {
    NODE * del = queue->head;
    process_t * r = del->p;
    queue->head = del->next;
    free (del);
    return r;
}

int srtf_is_empty (QUEUE * queue) {
    return queue->head == NULL;
}
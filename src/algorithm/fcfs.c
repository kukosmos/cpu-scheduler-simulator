#include <stdlib.h>

#include "fcfs.h"
#include "../cpu.h"

#define QUEUE struct __fcfs_queue
#define NODE struct __fcfs_node

struct __fcfs_node {
    Process * process;
    NODE * next;
};

struct __fcfs_queue {
    NODE * head;
    NODE * tail;
};

int fcfs_is_empty (QUEUE * queue) {
    return queue->head == NULL;
}

Process * fcfs_dequeue (QUEUE * queue) {
    NODE * del = queue->head;
    queue->head = del->next;
    Process * p = del->process;
    free (del);
    return p;
}

void * create_fcfs_queue () {
    QUEUE * queue = (QUEUE *) malloc (sizeof (QUEUE));
    queue->head = NULL;
    queue->tail = NULL;
    return (void *) queue;
}

void fcfs_scheduling (CPU_scheduler * this) {
    if (is_running (this->cpu)) {
        return;
    }
    if (fcfs_is_empty ((QUEUE *) this->queue)) {
        return;
    }
    execute (this->cpu, fcfs_dequeue ((QUEUE *) this->queue), NULL);
}

void fcfs_enqueue (void * arg, Process * process) {
    QUEUE * queue = (QUEUE *) arg;
    NODE * node = (NODE *) malloc (sizeof (NODE));
    node->process = process;
    node->next = NULL;
    queue->tail->next = node;
    queue->tail = node;
}
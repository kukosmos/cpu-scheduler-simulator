#include <stdlib.h>

#include "io_device.h"

#define QUEUE struct __io_queue
#define NODE struct __io_queue_node

#define RUNNING 1
#define STOP 0

void enqueue (QUEUE * queue, Process * p) {
    NODE * node = (NODE *) malloc (sizeof (NODE));
    node->process = p;
    node->prev = NULL;
    node->next = NULL;

    if (queue->head == NULL) {
        queue->head = node;
        queue->tail = node;    
    } else {
        node->prev = queue->tail;
        queue->tail->next = node;
        queue->tail = node;
    }
}

Process * dequeue (QUEUE * queue) {
    NODE * del = queue->head;
    Process * p = del->process;
    queue->head = queue->head->next;
    free (del);
    return p;
}

int is_queue_empth (QUEUE * queue) {
    return queue->head == NULL;
}

void * ioing (void * arg) {
    IO_device * this = (IO_device *) arg;
    int prev = -1;
    Process * p = NULL;
    while (this->state) {
        while (prev == get_time (this->clk)) {
            // no_op
        }
        prev = get_time (this->clk);
        if (p == NULL && is_queue_empth (this->queue)) {
            write (this->record, 0);
            continue;
        }
        if (p == NULL) {
            p = dequeue (this->queue);
        }
        write (this->record, p->pid);
        if (io (p)) {
            p = NULL;
        }
    }
}

IO_device * create_io_device (Clock * clk) {
    IO_device * io = (IO_device *) malloc (sizeof (IO_device));
    io->state = STOP;
    io->clk = clk;
    io->record = create_record ("IO device execution log", 24);
    io->queue = (QUEUE *) malloc (sizeof (QUEUE));

    return io;
}

void delete_io_device (IO_device * this) {
    if (this->state) {
        this->state = STOP;
        pthread_join (this->tid, NULL);
    }
    free (this->queue);
    free (this);
}

void start_io_device (IO_device * this) {
    if (this->state) {
        return;
    }
    this->state = RUNNING;
    pthread_t tid;
    pthread_create (&tid, NULL, ioing, this);
    this->tid = tid;
}

void stop_io_device (IO_device * this) {
    if (this->state) {
        this->state = STOP;
        pthread_join (this->tid, NULL);
    }
}

void io_request (IO_device * this, Process * p) {
    enqueue(this->queue, p);
}

void io_register_cpu_scheduler (IO_device * this, CPU_scheduler * cs) {
    this->cpu_scheduler = cs;
}
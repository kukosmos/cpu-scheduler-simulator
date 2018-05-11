#include <stdlib.h>

#include "io_device.h"
#include "cpu_scheduler.h"

#define QUEUE struct __io_queue
#define NODE struct __io_queue_node

void enqueue (QUEUE * queue, Process * p) {
    NODE * node = (NODE *) malloc (sizeof (NODE));
    node->process = p;
    node->next = NULL;

    if (queue->head == NULL) {
        queue->head = node;
        queue->tail = node;    
    } else {
        queue->tail->next = node;
        queue->tail = node;
    }
}

Process * io_dequeue (QUEUE * queue) {
    NODE * del = queue->head;
    Process * p = del->process;
    queue->head = queue->head->next;
    free (del);
    return p;
}

int is_queue_empth (QUEUE * queue) {
    return queue->head == NULL;
}

void ioing (IO_device * this) {
    if (this->process == NULL && is_queue_empth (this->queue)) {
        return;
    }
    if (this->process == NULL) {
        this->process = io_dequeue (this->queue);
    }
    write (this->record, this->process->pid);
    if (io (this->process)) {
        new_process (this->cpu_scheduler, this->process);
        this->process = NULL;
    }
}

IO_device * create_io_device (Clock * clk) {
    IO_device * io = (IO_device *) malloc (sizeof (IO_device));
    io->clk = clk;
    io->record = create_record ("IO device execution log", 24);
    io->queue = (QUEUE *) malloc (sizeof (QUEUE));

    return io;
}

void delete_io_node (NODE * del) {
    if (del->next != NULL) {
        delete_io_node (del->next);
    }
    free (del);
}

void delete_io_queue (QUEUE * queue) {
    if (queue->head != NULL) {
        delete_io_node (queue->head);
    }
    free (queue);
}

void delete_io_device (IO_device * this) {
    delete_io_queue (this->queue);
    free (this);
}

void io_request (IO_device * this, Process * p) {
    enqueue(this->queue, p);
}

void io_register_cpu_scheduler (IO_device * this, CPU_scheduler * cs) {
    this->cpu_scheduler = cs;
}
#include "../cpu.h"
#include "priority.h"
#include "np_priority.h"

#define QUEUE struct __priority_queue

void * create_np_priority_queue () {
    return (void *) create_priority_queue ();
}

void np_priority_shceduling (cpu_scheduler_t * this) {
    if (is_running (this->cpu)) {
        return;
    }
    if (priority_is_empty ((QUEUE *) this->queue)) {
        return;
    }
    process_t * orig;
    execute (this->cpu, priority_dequeue ((QUEUE *) this->queue), &orig);
}

void np_priority_enqueue (void * queue, process_t * process) {
    priority_enqueue ((QUEUE *) queue, process);
}
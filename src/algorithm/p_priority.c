#include "../cpu.h"
#include "priority.h"
#include "p_priority.h"

#define QUEUE struct __priority_queue

#define NULL 0

void * create_p_priority_queue () {
    return (void *) create_priority_queue ();
}

void p_priority_scheduling (cpu_scheduler_t * this) {
    if (priority_is_empty ((QUEUE *) this->queue)) {
        return;
    }
    if (is_running (this->cpu) && this->cpu->process->priority <= ((QUEUE *) this->queue)->head->p->priority) {
        // preemtion condition check
        return;
    }
    process_t * orig;
    execute (this->cpu, priority_dequeue ((QUEUE *) this->queue), &orig);
    if (orig != NULL) { // if preemted
        p_priority_enqueue (this->queue, orig);
    }
}

void p_priority_enqueue (void * queue, process_t * process) {
    priority_enqueue ((QUEUE *) queue, process);
}
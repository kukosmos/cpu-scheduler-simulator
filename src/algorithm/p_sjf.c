#include "../cpu.h"
#include "sjf.h"
#include "p_sjf.h"

#define QUEUE struct __sjf_queue

#define NULL 0

void * create_p_sjf_queue () {
    return (void *) create_sjf_queue ();
}

void p_sjf_scheduling (cpu_scheduler_t * this) {
    if (sjf_is_empty ((QUEUE *) this->queue)) {
        return;
    }
    if (is_running (this->cpu) && this->cpu->process->cpu_burst_time <= ((QUEUE *) this->queue)->head->p->cpu_burst_time) {
        // preemtion condition check
        return;
    }
    process_t * orig;
    execute (this->cpu, sjf_dequeue ((QUEUE *) this->queue), &orig);
    if (orig != NULL) { // if preempted
        p_sjf_enqueue (this->queue, orig);
    }
}

void p_sjf_enqueue (void * queue, process_t * process) {
    sjf_enqueue ((QUEUE *) queue, process);
}

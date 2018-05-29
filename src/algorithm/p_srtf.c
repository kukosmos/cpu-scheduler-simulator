#include "../cpu.h"
#include "srtf.h"
#include "p_sjf.h"

#define QUEUE struct __srtf_queue

#define NULL 0

void * create_p_srtf_queue () {
    return (void *) create_srtf_queue ();
}

void p_srtf_scheduling (cpu_scheduler_t * this) {
    if (srtf_is_empty ((QUEUE *) this->queue)) {
        return;
    }
    if (is_running (this->cpu) && this->cpu->process->cpu_remain_time <= ((QUEUE *) this->queue)->head->p->cpu_remain_time) {
        // preemption condition check
        return;
    }
    process_t * orig;
    execute (this->cpu, sjf_dequeue ((QUEUE *) this->queue), &orig);
    if (orig != NULL) { // if preempted
        p_srtf_enqueue (this->queue, orig);
    }
}

void p_srtf_enqueue (void * queue, process_t * process) {
    srtf_enqueue ((QUEUE *) queue, process);
}
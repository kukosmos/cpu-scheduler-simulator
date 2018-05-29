#include "../cpu.h"
#include "srtf.h"
#include "np_srtf.h"

#define QUEUE struct __srtf_queue

#define NULL 0

void * create_np_srtf_queue () {
    return (void *) create_srtf_queue ();
}

void np_srtf_scheduling (cpu_scheduler_t * this) {
    if (srtf_is_empty ((QUEUE *) this->queue)) {
        return;
    }
    if (is_running (this->cpu)) {
        return;
    }
    process_t * orig;
    execute (this->cpu, srtf_dequeue ((QUEUE *) this->queue), &orig);
}

void np_srtf_enqueue (void * queue, process_t * process) {
    srtf_enqueue ((QUEUE *) queue, process);
}
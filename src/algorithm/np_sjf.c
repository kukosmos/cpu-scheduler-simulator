#include "../cpu.h"
#include "sjf.h"
#include "np_sjf.h"

#define QUEUE struct __sjf_queue

void * create_np_sjf_queue () {
    return (void *) create_sjf_queue ();
}

void np_sjf_scheduling (cpu_scheduler_t * this) {
    if (is_running (this->cpu)) {
        return;
    }
    if (sjf_is_empty ((QUEUE *) this->queue)) {
        return;
    }
    process_t * orig;
    execute (this->cpu, sjf_dequeue ((QUEUE *) this->queue), &orig);
}

void np_sjf_enqueue (void * queue, process_t * process) {
    sjf_enqueue ((QUEUE *) queue, process);
}

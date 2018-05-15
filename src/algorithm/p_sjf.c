#include <stdlib.h>

#include "sjf.h"
#include "p_sjf.h"

#define QUEUE struct __sjf_queue

void * create_p_sjf_queue () {
    return (void *) create_sjf_queue ();
}

void p_sjf_scheduling (cpu_scheduler_t * this) {
    if (sjf_is_empty ((QUEUE *) this->queue)) {
        return;
    }
    process_t * orig;
    execute (this->cpu, sjf_dequeue ((QUEUE *) this->queue), &orig);
    if (orig != NULL) {
        p_sjf_enqueue (this->queue, orig);
    }
}

void p_sjf_enqueue (void * queue, process_t * process) {
    sjf_enqueue ((QUEUE *) queue, process);
}

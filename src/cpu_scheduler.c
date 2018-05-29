#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "cpu_scheduler.h"

#include "algorithm/fcfs.h"
#include "algorithm/np_sjf.h"
#include "algorithm/p_sjf.h"
#include "algorithm/np_priority.h"
#include "algorithm/p_priority.h"
#include "algorithm/rr.h"
#include "algorithm/p_srtf.h"

cpu_scheduler_t * create_cpu_scheduler (char * algo, clk_t * clock, ...) {
    cpu_scheduler_t * cs = (cpu_scheduler_t *) malloc (sizeof (cpu_scheduler_t));

    cs->algo = (char *) malloc (sizeof (algo));
    memcpy (cs->algo, algo, sizeof (algo));
    cs->clk = clock;

    if (strcmp ("fcfs", algo) == 0) {
        cs->queue = create_fcfs_queue ();
        cs->enqueue = fcfs_enqueue;
        cs->scheduling = fcfs_scheduling;
    } else if (strcmp ("np_sjf", algo) == 0) {
        cs->queue = create_np_sjf_queue ();
        cs->enqueue = np_sjf_enqueue;
        cs->scheduling = np_sjf_scheduling;    
    } else if (strcmp ("p_sjf", algo) == 0) {
        cs->queue = create_p_sjf_queue ();
        cs->enqueue = p_sjf_enqueue;
        cs->scheduling = p_sjf_scheduling;
    } else if (strcmp ("np_priority", algo) == 0) {
        cs->queue = create_np_priority_queue ();
        cs->enqueue = np_priority_enqueue;
        cs->scheduling = np_priority_scheduling;
    } else if (strcmp ("p_priority", algo) == 0) {
        cs->queue = create_p_priority_queue ();
        cs->enqueue = p_priority_enqueue;
        cs->scheduling = p_priority_scheduling;
    } else if (strcmp ("rr", algo) == 0) {
        va_list vl;
        va_start (vl, 1);
        cs->queue = create_rr_queue (va_arg (vl, int));
        va_end (vl);
        cs->enqueue = rr_enqueue;
        cs->scheduling = rr_scheduling;
    } else if (strcmp ("np_srtf", algo) == 0) {
        
        return NULL;
    } else if (strcmp ("p_srtf", algo) == 0) {
        cs->queue = create_p_srtf_queue ();
        cs->enqueue = p_srtf_enqueue;
        cs->scheduling = p_srtf_scheduling;
    } else {
        free (cs);
        return NULL;
    }

    return cs;
}

void delete_cpu_scheduler (cpu_scheduler_t * this) {
    free (this->queue);
    free (this);
}

void register_cpu (cpu_scheduler_t * this, cpu_t * cpu) {
    this->cpu = cpu;
}

void new_process (cpu_scheduler_t * this, process_t * proc) {
    this->enqueue (this->queue, proc);
}

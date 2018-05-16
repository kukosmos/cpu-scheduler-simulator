#include <stdlib.h>
#include <string.h>

#include "cpu_scheduler.h"

#include "algorithm/fcfs.h"
#include "algorithm/np_sjf.h"
#include "algorithm/p_sjf.h"
#include "algorithm/np_priority.h"
#include "algorithm/p_priority.h"
#include "algorithm/rr.h"

#define TRUE 1
#define FALSE 0

/* return TRUE when orig and targ are equal
 */
int str_compare (char * orig, char * targ) {
    int result = TRUE;
    while (*orig != 0) {
        if (*orig != *targ) {
            result = FALSE;
            break;
        }
        orig++;
        targ++;
    }
    if (*targ != 0) {
        result = FALSE;
    }
    return result;
}

cpu_scheduler_t * create_cpu_scheduler (char * algo, clk_t * clock) {
    cpu_scheduler_t * cs = (cpu_scheduler_t *) malloc (sizeof (cpu_scheduler_t));

    cs->algo = (char *) malloc (sizeof (algo));
    memcpy (cs->algo, algo, sizeof (algo));
    cs->clk = clock;

    if (str_compare ("fcfs", algo)) {
        cs->queue = create_fcfs_queue ();
        cs->enqueue = fcfs_enqueue;
        cs->scheduling = fcfs_scheduling;
    } else if (str_compare ("np_sjf", algo)) {
        cs->queue = create_np_sjf_queue ();
        cs->enqueue = np_sjf_enqueue;
        cs->scheduling = np_sjf_scheduling;    
    } else if (str_compare ("p_sjf", algo)) {
        cs->queue = create_p_sjf_queue ();
        cs->enqueue = p_sjf_enqueue;
        cs->scheduling = p_sjf_scheduling;
    } else if (str_compare ("np_priority", algo)) {
        cs->queue = create_np_priority_queue ();
        cs->enqueue = np_priority_enqueue;
        cs->scheduling = np_priority_scheduling;
    } else if (str_compare ("p_priority", algo)) {
        cs->queue = create_p_priority_queue ();
        cs->enqueue = p_priority_enqueue;
        cs->scheduling = p_priority_scheduling;
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

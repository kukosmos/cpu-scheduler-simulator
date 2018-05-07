#include <stdlib.h>

#include "cpu_scheduler.h"

#include "algorithm/fcfs.h"
#include "algorithm/np_sjf.h"
#include "algorithm/p_sjf.h"
#include "algorithm/np_priority.h"
#include "algorithm/p_priority.h"
#include "algorithm/rr.h"

#define TRUE 1
#define FALSE 0

#define RUNNING 1
#define STOP 0

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

CPU_scheduler * create_cpu_scheduler (char * algo, Clock * clock) {
    CPU_scheduler * cs = (CPU_scheduler *) malloc (sizeof (CPU_scheduler));

    cs->algo = algo;
    cs->clk = clock;

    if (str_compare ("fcfs", algo)) {
        cs->queue = create_fcfs_queue ();
        cs->enqueue = fcfs_enqueue;
        cs->scheduling = fcfs_scheduling;
    } else {
        free (cs);
        return NULL;
    }

    return cs;
}

void delete_cpu_scheduler (CPU_scheduler * this) {
    free (this->queue);
    free (this);
}

void new_process (CPU_scheduler * this, Process * proc) {
    this->enqueue (this->queue, proc);
}

void start_cpu_scheduling (CPU_scheduler * this) {
    pthread_t tid;
    this->state = RUNNING;
    pthread_create (&tid, NULL, this->scheduling, this);
    this->tid = tid;
}

void stop_cpu_scheduling (CPU_scheduler * this) {
    this->state = STOP;
    pthread_join (this->tid, NULL);
}
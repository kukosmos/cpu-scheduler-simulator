#include <stdlib.h>

#include "cpu.h"

#define STOP 0
#define RUNNING 1

/* while executing
 * cpu decrease cpu remain time of process by 1
 */
void * executing (void * arg) {
    CPU * this = (CPU *) arg;
    int prev = -1;
    while (this->state) {
        while (prev == get_time (this->clk)) {
            // op_op    // busy waiting
        }
        prev = get_time (this->clk);
        if (this->process == NULL) {    // idle
            write (this->record, 0);
        } else {
            write (this->record, this->process->pid);
            if (run (this->process)) {
                this->process = NULL;
            }
            if (this->process->io_start_time == get_time (this->clk)) {
                start_io (this->io, this->process);
                this->process = NULL;
            }
        }
    }
}

CPU * create_cpu (Clock * clk) {
    CPU * cpu = (CPU *) malloc (sizeof (CPU));
    cpu->state = STOP;
    cpu->clk = clk;
    cpu->record = create_record ("CPU execution log", 18);
    
    return cpu;
}

void delete_cpu (CPU * this) {
    if (this->state) {
        this->state = STOP;
        pthread_join (this->tid, NULL);
    }
    delete_record (this->record);
    free (this);
}

void start_running (CPU * this) {
    if (this->state) {
        // no_op
    } else {
        pthread_t tid;
        this->state = RUNNING;
        pthread_create (&tid, NULL, executing, this);
        this->tid = tid;
    }
}

void stop_running (CPU * this) {
    if (this->state) {
        this->state = STOP;
        pthread_join (this->tid, NULL);
    } else {
        // no_op
    }
}

int is_running (CPU * this) {
    return this->process != NULL;
}

void execute (CPU * this, Process * new, Process ** orig) {
    *orig = this->process;
    this->process = new;
}
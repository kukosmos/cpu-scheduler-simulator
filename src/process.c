#include <stdlib.h>

#include "process.h"

/* arrival time can have value
 * from 0
 * to MAX_ARRIVAL_TIME - 1
 */
#define MAX_ARRIVAL_TIME 10

/* CPU/IO burst time can have value
 * from MIN_BURST_TIME
 * to MAX_BURST_TIME - 1
 */
#define MIN_BURST_TIME 1
#define MAX_BURST_TIME 20

/* priority can have value
 * from 0
 * to MAX_PRIORITY - 1
 */
#define MAX_PRIORITY 5

Process * create_process (unsigned int pid) {
    if (pid == 0) {
        return NULL;
    }
    Process * p = (Process *) malloc (sizeof (Process));

    p->pid = pid;

    p->arrival_time = rand() % MAX_ARRIVAL_TIME;
    p->cpu_burst_time = rand() % (MAX_BURST_TIME - MIN_BURST_TIME) + MIN_BURST_TIME;
    p->cpu_remain_time = p->cpu_burst_time;

    if (p->cpu_burst_time > 1) {
        p->io_start_time = rand() % (p->cpu_burst_time - 1) + 1;    // io start time can have value from 1 to cpu burst time - 1
        p->io_burst_time = rand() % (MAX_BURST_TIME - MIN_BURST_TIME) + MIN_BURST_TIME;
        p->io_remain_time = p->io_burst_time;
    }

    p->priority = rand() % (MAX_PRIORITY);

    return p;
}

int run (Process * this) {
    this->cpu_remain_time = this->cpu_remain_time - 1;
    return this->cpu_remain_time == 0;
}

int io (Process * this) {
    this->io_remain_time = this->io_remain_time - 1;
    return this->io_remain_time == 0;
}

void delete_process (Process * this) {
    free (this);
}
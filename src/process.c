#include <stdlib.h>

#include "process.h"

/* arrival time can have value
 * from 0
 * to MAX_ARRIVAL_TIME - 1
 */
#define MAX_ARRIVAL_TIME 10

/* CPU burst time can have value
 * from MIN_CPU_BURST_TIME
 * to MAX_CPU_BURST_TIME - 1
 */
#define MIN_CPU_BURST_TIME 5
#define MAX_CPU_BURST_TIME 20

/* IO burst time can have value
 * from MIN_IO_BURST_TIME
 * to MAX_IO_BURST_TIME - 1
 * if IO burst time have value
 * from MAX_IO_BURST_TIME
 * to MAX_IO_RAND_TIME,
 * there is no IO operation in process
 */
#define MIN_IO_BURST_TIME 1
#define MAX_IO_BURST_TIME 10
#define MAX_IO_RAND_TIME 20

/* priority can have value
 * from 0
 * to MAX_PRIORITY - 1
 */
#define MAX_PRIORITY 5

process_t * create_process (unsigned int pid) {
    if (pid == 0) {
        return NULL;
    }
    process_t * p = (process_t *) malloc (sizeof (process_t));

    p->pid = pid;

    p->arrival_time = rand() % MAX_ARRIVAL_TIME;
    p->cpu_burst_time = rand() % (MAX_CPU_BURST_TIME - MIN_CPU_BURST_TIME) + MIN_CPU_BURST_TIME;
    p->cpu_remain_time = p->cpu_burst_time;
    p->termination_time = 0;

    if (p->cpu_burst_time > 1) {
        p->io_burst_time = rand() % (MAX_IO_RAND_TIME - MIN_IO_BURST_TIME) + MIN_IO_BURST_TIME;
        if (p->io_burst_time < MAX_IO_BURST_TIME) {
            p->io_start_time = rand() % (p->cpu_burst_time - 1) + 1;    // io start time can have value from 1 to cpu burst time - 1
        } else {
            p->io_burst_time = 0;
            p->io_start_time = 0;
        }
        p->io_remain_time = p->io_burst_time;
    } else {
        p->io_burst_time = 0;
        p->io_start_time = 0;
        p->io_remain_time = 0;
    }

    p->priority = rand() % (MAX_PRIORITY);

    return p;
}

int run (process_t * this) {
    this->cpu_remain_time = this->cpu_remain_time - 1;
    return this->cpu_remain_time == 0;
}

int io (process_t * this) {
    this->io_remain_time = this->io_remain_time - 1;
    return this->io_remain_time == 0;
}

void delete_process (process_t * this) {
    free (this);
}
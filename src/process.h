#ifndef __PROCESS_H
#define __PROCESS_H

struct __process {
    unsigned int pid;

    unsigned int arrival_time;
    unsigned int cpu_burst_time;
    unsigned int cpu_remain_time;

    unsigned int io_start_time;
    unsigned int io_burst_time;
    unsigned int io_remain_time;

    unsigned int priority;
};

typedef struct __process Process;

/* create new process with pid = pid
 * pid can have value from 1 (0 means idle)
 * you SHOULD call srand before call create_process
 */
Process * create_process (unsigned int pid);

/* decrease cpu remain time by 1
 * return TRUE when cpu remain time becomes 0
 */
int run (Process * process);

/* decrease io remain time by 1
 * return TRUE when io remain time becoms 0
 */
int io (Process * process);

/* delete process
 */
void delete_process (Process * process);

#endif

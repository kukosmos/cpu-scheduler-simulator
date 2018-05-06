#ifndef __PROCESS_H
#define __PROCESS_H

struct __process {
    unsigned int pid;

    unsigned int arrival_time;
    unsigned int cpu_burst_time;
    unsigned int remain_time;

    unsigned int io_start_time;
    unsigned int io_burst_time;
    unsigned int io_remain_time;

    unsigned int priority;
};

typedef struct __process Process;

/* create new process with pid = pid
 * you SHOULD call srand before call create_process
 */
Process * create_process (unsigned int pid);

/* decrease remain_time by 1
 * return TRUE when remain_time becomes 0
 */
int run (Process * process);

/* decrease io_remain_time by 1
 * return TRUE when io_remain_time becoms 0
 */
int io (Process * process);

/* delete process
 */
void delete_process (Process * process);

#endif

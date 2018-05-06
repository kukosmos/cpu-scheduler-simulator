#ifndef __CPU_SCHEDULER_H
#define __CPU_SCHEDULER_H

struct __cpu_scheduler {

};

typedef struct __cpu_scheduler CPU_scheduler;

void new_process (CPU_scheduler * cpu_scheduler, Process * process);

#endif

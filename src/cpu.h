#ifndef __CPU_H
#define __CPU_H

#include "clock.h"
#include "process.h"
#include "record.h"
#include "io_device.h"

struct __cpu {
    Clock * clk;
    Record * record;
    IO_device * io;
    Process * process;
};

typedef struct __cpu CPU;

/* create cpu
 */
CPU * create_cpu (Clock * clock);

/* delete cpu
 */
void delete_cpu (CPU * cpu);

/* execute cpu for one clock
 */
void running (CPU * cpu);

/* return if cpu has a process running
 */
int is_running (CPU * cpu);

/* schedule new process to cpu
 * if there is a process already running,
 * orig will store that process
 */
void execute (CPU * cpu, Process * new, Process ** orig);

/* register io device
 */
void register_io_device (CPU * cpu, IO_device * io_device);

#endif

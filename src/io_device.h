#ifndef __IO_DEVICE_H
#define __IO_DEVICE_H

#include "clock.h"
#include "process.h"
#include "record.h"

// due to cyclic inclustion
#ifndef __DEF_TYPE_CPU_SCHEDULER
#define __DEF_TYPE_CPU_SCHEDULER
typedef struct __cpu_scheduler CPU_scheduler;
#endif

struct __io_queue_node {
    Process * process;
    struct __io_queue_node * next;
};

struct __io_queue {
    struct __io_queue_node * head;
    struct __io_queue_node * tail;
};

struct __io_device {
    Process * process;
    Clock * clk;
    Record * record;
    CPU_scheduler * cpu_scheduler;
    struct __io_queue * queue;
};

typedef struct __io_device IO_device;

/* create io device
 */
IO_device * create_io_device (Clock * clock);

/* delete io device
 */
void delete_io_device (IO_device * io_device);

/* request io
 * if there are some process running enqueue
 * queue works FIFO
 */
void io_request (IO_device * io_device, Process * process);

/* register cpu scheduler
 */
void io_register_cpu_scheduler (IO_device * io_device, CPU_scheduler * cpu_scheduler);

/* execute io device for one clock cycle
 */
void ioing (IO_device * io_device);

#endif

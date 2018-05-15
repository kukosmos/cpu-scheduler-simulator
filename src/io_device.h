#ifndef __IO_DEVICE_H
#define __IO_DEVICE_H

#include "clock.h"
#include "process.h"
#include "record.h"

/* due to cyclic inclustion
 * decare typedef instead of include cpu_scheduler.h
 */
#ifndef __DEF_TYPE_CPU_SCHEDULER
#define __DEF_TYPE_CPU_SCHEDULER
typedef struct __cpu_scheduler cpu_scheduler_t;
#endif

struct __io_queue_node {
    process_t * process;
    struct __io_queue_node * next;
};

struct __io_queue {
    struct __io_queue_node * head;
    struct __io_queue_node * tail;
};

struct __io_device {
    process_t * process;
    clk_t * clk;
    record_t * record;
    cpu_scheduler_t * cpu_scheduler;
    struct __io_queue * queue;
};

typedef struct __io_device io_device_t;

/* create io device
 */
io_device_t * create_io_device (clk_t * clock);

/* delete io device
 */
void delete_io_device (io_device_t * io_device);

/* request io
 * if there are some process running enqueue
 * queue works FIFO
 */
void io_request (io_device_t * io_device, process_t * process);

/* register cpu scheduler
 */
void io_register_cpu_scheduler (io_device_t * io_device, cpu_scheduler_t * cpu_scheduler);

/* execute io device for one clock cycle
 */
void ioing (io_device_t * io_device);

#endif

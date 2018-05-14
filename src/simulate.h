#ifndef __SIMULATE_H
#define __SIMULATE_H

#include "clock.h"
#include "job_scheduler.h"
#include "cpu_scheduler.h"
#include "cpu.h"
#include "io_device.h"

void start_simulate (clk_t * clk, job_scheduler_t * job_scheduler, cpu_scheduler_t * cpu_scheduler, cpu_t * cpu, io_device_t * io_device);

#endif

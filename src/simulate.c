#include <stdio.h>

#include "simulate.h"

void start_simulate (clk_t * clk, job_scheduler_t * js, cpu_scheduler_t * cs, cpu_t * cpu, io_device_t * io) {
    printf("start simulating\n");
    while (!all_terminated (js)) {
        job_scheduling (js);
        cs->scheduling (cs);
        ioing (io);
        running (cpu);
        clocking (clk);
    }
}
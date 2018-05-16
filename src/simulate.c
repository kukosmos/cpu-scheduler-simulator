#include <stdio.h>

#include "simulate.h"

void start_simulate (clk_t * clk, job_scheduler_t * js, cpu_scheduler_t * cs, cpu_t * cpu, io_device_t * io) {
    js_register_cpu_scheduler (js, cs);
    register_cpu (cs, cpu);
    register_io_device (cpu, io);
    io_register_cpu_scheduler (io, cs);
    init_clock (clk);

    printf ("start simulating\n");
    while (!all_terminated (js)) {
        job_scheduling (js);
        cs->scheduling (cs);
        ioing (io);
        running (cpu);
        clocking (clk);
    }
}
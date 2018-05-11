#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "process.h"
#include "clock.h"
#include "job_scheduler.h"
#include "cpu_scheduler.h"
#include "cpu.h"
#include "io_device.h"

int main (int argc, char ** argv) {
    printf("KOSMOS PROJECT\nCPU Scheduler Simulator\n");

    srand (time (NULL));

    Clock * clk = create_clock ();
    Job_scheduler * js = create_job_scheduler (clk);
    CPU_scheduler * cs = create_cpu_scheduler ("fcfs", clk);
    CPU * cpu = create_cpu (clk);
    IO_device * io = create_io_device (clk);
    
    js_register_cpu_scheduler (js, cs);
    register_cpu (cs, cpu);
    register_io_device (cpu, io);
    io_register_cpu_scheduler (io, cs);
    
    create_processes (js, 10);
    print_processes (js);

    while (!all_terminated (js)) {
        // no_op
    }

    show_gantt_chart (cpu->record);

    delete_io_device (io);
    delete_cpu (cpu);
    delete_cpu_scheduler (cs);
    delete_job_scheduler (js);
    delete_clock (clk);

    return 0;
}
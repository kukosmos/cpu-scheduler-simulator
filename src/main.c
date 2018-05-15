#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "simulate.h"
#include "clock.h"
#include "job_scheduler.h"
#include "cpu_scheduler.h"
#include "cpu.h"
#include "io_device.h"

int main (int argc, char ** argv) {
    printf("KOSMOS PROJECT\nCPU Scheduler Simulator\n");

    srand (time (NULL));

    clk_t * clk = create_clock ();
    job_scheduler_t * js = create_job_scheduler (clk);
    cpu_scheduler_t * cs = create_cpu_scheduler ("fcfs", clk);
    cpu_t * cpu = create_cpu (clk);
    io_device_t * io = create_io_device (clk);
    
    create_processes (js, 10);
    print_processes (js);

    start_simulate (clk, js, cs, cpu, io);

    printf("FCFS gantt chart\n");
    show_gantt_chart (cpu->record);
    printf("IO device gantt chart\n");
    show_gantt_chart (io->record);

    delete_cpu_scheduler (cs);

    cs = create_cpu_scheduler ("np_sjf", clk);
    reset_record (cpu->record);
    reset_record (io->record);
    reset_job_scheduling (js);
    start_simulate (clk, js, cs, cpu, io);

    printf("Non-preemptive SJF gantt chart\n");
    show_gantt_chart (cpu->record);
    printf("IO device gantt chart\n");
    show_gantt_chart (io->record);

    delete_io_device (io);
    delete_cpu (cpu);
    delete_cpu_scheduler (cs);
    delete_job_scheduler (js);
    delete_clock (clk);

    return 0;
}
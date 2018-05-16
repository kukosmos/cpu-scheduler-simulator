#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "simulate.h"
#include "option.h"
#include "clock.h"
#include "job_scheduler.h"
#include "cpu_scheduler.h"
#include "cpu.h"
#include "io_device.h"

int main (int argc, char ** argv) {
    printf ("KOSMOS PROJECT\nCPU Scheduler Simulator\n");

    // default setting
    srand (time (NULL));

    option_t opt;
    parse_option (argc, argv, &opt);

    if (opt.help) {
        return 0;
    }

    clk_t * clk = create_clock ();
    job_scheduler_t * js = create_job_scheduler (clk);
    cpu_t * cpu = create_cpu (clk);
    io_device_t * io = create_io_device (clk);
    cpu_scheduler_t * cs;
    
    create_processes (js, opt.num_of_processes);
    print_processes (js);

    // FCFS
    if (opt.test_fcfs) {
        cs = create_cpu_scheduler ("fcfs", clk);
        start_simulate (clk, js, cs, cpu, io);

        printf ("FCFS gantt chart\n");
        show_gantt_chart (cpu->record);
        // printf ("IO device gantt chart\n");
        // show_gantt_chart (io->record);

        delete_cpu_scheduler (cs);
    }

    // non-preemptive SJF
    if (opt.test_np_sjf) {
        cs = create_cpu_scheduler ("np_sjf", clk);
        reset_record (cpu->record);
        reset_record (io->record);
        reset_job_scheduling (js);
        start_simulate (clk, js, cs, cpu, io);

        printf ("Non-preemptive SJF gantt chart\n");
        show_gantt_chart (cpu->record);
        // printf ("IO device gantt chart\n");
        // show_gantt_chart (io->record);

        delete_cpu_scheduler (cs);
    }
    
    // preemptive SJF
    if (opt.test_p_sjf) {
        cs = create_cpu_scheduler ("p_sjf", clk);
        reset_record (cpu->record);
        reset_record (io->record);
        reset_job_scheduling (js);
        start_simulate (clk, js, cs, cpu, io);

        printf ("Preemptive SJF gantt chart\n");
        show_gantt_chart (cpu->record);
        // printf ("IO device gantt chart\n");
        // show_gantt_chart (io->record);

        delete_cpu_scheduler (cs);
    }

    // non-preemptive priority
    if (opt.test_np_priority) {
        cs = create_cpu_scheduler ("np_priority", clk);
        reset_record (cpu->record);
        reset_record (io->record);
        reset_job_scheduling (js);
        start_simulate (clk, js, cs, cpu, io);

        printf ("Non-preemptive priority gantt chart\n");
        show_gantt_chart (cpu->record);
        // printf ("IO device gantt chart\n");
        // show_gantt_chart (io->record);

        delete_cpu_scheduler (cs);
    }
    
    // preemptive priority
    if (opt.test_p_priority) {
        cs = create_cpu_scheduler ("p_priority", clk);
        reset_record (cpu->record);
        reset_record (io->record);
        reset_job_scheduling (js);
        start_simulate (clk, js, cs, cpu, io);

        printf ("Preemptive priority gantt chart\n");
        show_gantt_chart (cpu->record);
        // printf ("IO device gantt chart\n");
        // show_gantt_chart (io->record);

        delete_cpu_scheduler (cs);
    }
    
    // round robin
    if (opt.test_rr) {
        cs = create_cpu_scheduler ("rr", clk, opt.round_robin_time_quantum);
        reset_record (cpu->record);
        reset_record (io->record);
        reset_job_scheduling (js);
        start_simulate (clk, js, cs, cpu, io);

        printf ("Round-robin gantt chart\n");
        show_gantt_chart (cpu->record);
        // printf ("IO device gantt chart\n");
        // show_gantt_chart (io->record);

        delete_cpu_scheduler (cs);
    }
    
    // free all allocated memory
    delete_io_device (io);
    delete_cpu (cpu);
    delete_job_scheduler (js);
    delete_clock (clk);

    return 0;
}
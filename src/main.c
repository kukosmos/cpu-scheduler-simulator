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
#include "evaluate.h"

int main (int argc, char ** argv) {
    option_t opt;
    parse_option (argc, argv, &opt);

    if (opt.help) {
        return 0;
    }

    printf ("KOSMOS PROJECT\nCPU Scheduler Simulator\n");

    // default setting
    srand (time (NULL));


    clk_t * clk = create_clock ();
    job_scheduler_t * js = create_job_scheduler (clk);
    cpu_t * cpu = create_cpu (clk);
    io_device_t * io = create_io_device (clk);
    cpu_scheduler_t * cs;
    
    create_processes (js, opt.num_of_processes);
    print_processes (js);

    process_t * process_list = (process_t *) malloc (sizeof (process_t *) * (opt.num_of_processes + 1));
    int * turn_around_time_list = (int *) malloc (sizeof (int) * (opt.num_of_processes + 1));
    int * waiting_time_list = (int *) malloc (sizeof (int) * (opt.num_of_processes + 1));
    double average_turn_around_time;
    double average_waiting_time;

    get_processes (js, process_list);

    // FCFS
    if (opt.test_fcfs) {
        cs = create_cpu_scheduler ("fcfs", clk);

        printf ("FCFS\n");
        start_simulate (clk, js, cs, cpu, io);

        average_turn_around_time = evaluate_turn_around_time (opt.num_of_processes, process_list, turn_around_time_list);
        printf ("average turn around time = %.2f\n", average_turn_around_time);
        printf ("turn around time\n");
        print_list ("turn around time", opt.num_of_processes, turn_around_time_list);

        average_waiting_time = evaluate_waiting_time (opt.num_of_processes, process_list, waiting_time_list);
        printf ("average waiting time = %.2f\n", average_waiting_time);
        printf ("waiting time\n");
        print_list ("waiting time", opt.num_of_processes, waiting_time_list);

        printf ("gantt chart\n");
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

        printf ("Non-preemptive SJF\n");
        start_simulate (clk, js, cs, cpu, io);
        
        average_turn_around_time = evaluate_turn_around_time (opt.num_of_processes, process_list, turn_around_time_list);
        printf ("average turn around time = %.2f\n", average_turn_around_time);
        printf ("turn around time\n");
        print_list ("turn around time", opt.num_of_processes, turn_around_time_list);

        average_waiting_time = evaluate_waiting_time (opt.num_of_processes, process_list, waiting_time_list);
        printf ("average waiting time = %.2f\n", average_waiting_time);
        printf ("waiting time\n");
        print_list ("waiting time", opt.num_of_processes, waiting_time_list);

        printf ("gantt chart\n");
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

        printf ("Preemptive SJF\n");
        start_simulate (clk, js, cs, cpu, io);

        average_turn_around_time = evaluate_turn_around_time (opt.num_of_processes, process_list, turn_around_time_list);
        printf ("average turn around time = %.2f\n", average_turn_around_time);
        printf ("turn around time\n");
        print_list ("turn around time", opt.num_of_processes, turn_around_time_list);

        average_waiting_time = evaluate_waiting_time (opt.num_of_processes, process_list, waiting_time_list);
        printf ("average waiting time = %.2f\n", average_waiting_time);
        printf ("waiting time\n");
        print_list ("waiting time", opt.num_of_processes, waiting_time_list);

        printf ("gantt chart\n");
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

        printf ("Non-preemptive priority\n");
        start_simulate (clk, js, cs, cpu, io);

        average_turn_around_time = evaluate_turn_around_time (opt.num_of_processes, process_list, turn_around_time_list);
        printf ("average turn around time = %.2f\n", average_turn_around_time);
        printf ("turn around time\n");
        print_list ("turn around time", opt.num_of_processes, turn_around_time_list);

        average_waiting_time = evaluate_waiting_time (opt.num_of_processes, process_list, waiting_time_list);
        printf ("average waiting time = %.2f\n", average_waiting_time);
        printf ("waiting time\n");
        print_list ("waiting time", opt.num_of_processes, waiting_time_list);

        printf ("gantt chart\n");
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

        printf ("Preemptive priority\n");
        start_simulate (clk, js, cs, cpu, io);

        average_turn_around_time = evaluate_turn_around_time (opt.num_of_processes, process_list, turn_around_time_list);
        printf ("average turn around time = %.2f\n", average_turn_around_time);
        printf ("turn around time\n");
        print_list ("turn around time", opt.num_of_processes, turn_around_time_list);
        
        average_waiting_time = evaluate_waiting_time (opt.num_of_processes, process_list, waiting_time_list);
        printf ("average waiting time = %.2f\n", average_waiting_time);
        printf ("waiting time\n");
        print_list ("waiting time", opt.num_of_processes, waiting_time_list);

        printf ("gantt chart\n");
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

        printf ("Round-robin\n");
        start_simulate (clk, js, cs, cpu, io);

        average_turn_around_time = evaluate_turn_around_time (opt.num_of_processes, process_list, turn_around_time_list);
        printf ("average turn around time = %.2f\n", average_turn_around_time);
        printf ("turn around time\n");
        print_list ("turn around time", opt.num_of_processes, turn_around_time_list);

        average_waiting_time = evaluate_waiting_time (opt.num_of_processes, process_list, waiting_time_list);
        printf ("average waiting time = %.2f\n", average_waiting_time);
        printf ("waiting time\n");
        print_list ("waiting time", opt.num_of_processes, waiting_time_list);

        printf ("gantt chart\n");
        show_gantt_chart (cpu->record);
        // printf ("IO device gantt chart\n");
        // show_gantt_chart (io->record);

        delete_cpu_scheduler (cs);
    }

    // non-preemptive SRTF
    if (opt.test_np_srtf) {

    }

    // preemptive SRTF
    if (opt.test_p_srtf) {
        cs = create_cpu_scheduler ("p_srtf", clk);
        reset_record (cpu->record);
        reset_record (io->record);
        reset_job_scheduling (js);

        printf ("Preemptive SRTF\n");
        start_simulate (clk, js, cs, cpu, io);

        average_turn_around_time = evaluate_turn_around_time (opt.num_of_processes, process_list, turn_around_time_list);
        printf ("average turn around time = %.2f\n", average_turn_around_time);
        printf ("turn around time\n");
        print_list ("turn around time", opt.num_of_processes, turn_around_time_list);

        average_waiting_time = evaluate_waiting_time (opt.num_of_processes, process_list, waiting_time_list);
        printf ("average waiting time = %.2f\n", average_waiting_time);
        printf ("waiting time\n");
        print_list ("waiting time", opt.num_of_processes, waiting_time_list);

        printf ("gantt chart\n");
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

    free (process_list);

    return 0;
}
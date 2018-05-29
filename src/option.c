#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "option.h"

#define TRUE 1
#define FALSE 0

#define DEFAULT_NUM_PROCESS 10
#define DEFAULT_TIME_QUANTUM 4

void parse_option (int argc, char ** argv, option_t * opt) {
    // default
    opt->help = FALSE;
    opt->test_fcfs = FALSE;
    opt->test_np_sjf = FALSE;
    opt->test_p_sjf = FALSE;
    opt->test_np_priority = FALSE;
    opt->test_p_priority = FALSE;
    opt->test_rr = FALSE;
    opt->test_np_srtf = FALSE;
    opt->test_p_srtf = FALSE;
    opt->num_of_processes = DEFAULT_NUM_PROCESS;
    opt->round_robin_time_quantum = DEFAULT_TIME_QUANTUM;

    for (int i = 1; i < argc; i++) {
        if (strcmp ("-n", argv [i]) == 0) {
            i++;
            opt->num_of_processes = atoi (argv [i]);
        } else if (strcmp ("-tq", argv [i]) == 0) {
            i++;
            opt->round_robin_time_quantum = atoi (argv [i]);
        } else if (strcmp ("-h", argv [i]) == 0 || strcmp ("--help", argv [i]) == 0) {
            printf ("Usage: simulator <options> <scheduler options>\n");
            printf ("\n");
            printf ("options are:\n");
            printf ("   -h, --help      show the list of options\n");
            printf ("   -n <int>        number of processes to create (default : %d)\n", DEFAULT_NUM_PROCESS);
            printf ("   -tq <int>       size of time quantum of round-robin scheduler (default : %d)\n", DEFAULT_TIME_QUANTUM);
            printf ("\n");
            printf ("with no scheduler options simulate all cpu scheduler algorithms\n");
            printf ("scheduler options are:\n");
            printf ("   --fcfs          simulate Fisrt Come First Served\n");
            printf ("   --np-sjf        simulate Non-Preemptive Shortest Job First\n");
            printf ("   --p-sjf         simulate Preemptive Shortest Job First\n");
            printf ("   --np-priority   simulate Non-Preemptive Priority\n");
            printf ("   --p-priority    simulate Preemptive Priority\n");
            printf ("   --rr            simulate Round Robin\n");
            printf ("   --np-srtf       simulate Non-Preemptive Shortest Remain Time First\n");
            printf ("   --p-srtf        simulate Preemptive Shortest Remain Time First\n");
            printf ("\n");
            printf ("Korea Univ. KOSMOS\n");
            opt->help = TRUE;
            return;
        } else if (strcmp ("--fcfs", argv [i]) == 0) {
            opt->test_fcfs = TRUE;
        } else if (strcmp ("--np-sjf", argv [i]) == 0) {
            opt->test_np_sjf = TRUE;
        } else if (strcmp ("--p-sjf", argv [i]) == 0) {
            opt->test_p_sjf = TRUE;
        } else if (strcmp ("--np-priority", argv [i]) == 0) {
            opt->test_np_priority = TRUE;
        } else if (strcmp ("--p-priority", argv [i]) == 0) {
            opt->test_p_priority = TRUE;
        } else if (strcmp ("--rr", argv [i]) == 0) {
            opt->test_rr = TRUE;
        } else if (strcmp ("--np-srtf", argv [i]) == 0) {
            opt->test_np_srtf = TRUE;
        } else if (strcmp ("--p-srtf", argv [i]) == 0) {
            opt->test_p_srtf = TRUE;
        } else {
            opt->help = TRUE;
            printf ("Please check arguments\n");
            printf ("   \'simulator -h\' or \'simulator --help\' for help\n");
            return;
        }
    }
    if (!opt->test_fcfs
    && !opt->test_np_sjf
    && !opt->test_p_sjf
    && !opt->test_np_priority
    && !opt->test_p_priority
    && !opt->test_rr
    && !opt->test_np_srtf
    && !opt->test_p_srtf) {
        // if all false
        opt->test_fcfs = TRUE;
        opt->test_np_sjf = TRUE;
        opt->test_p_sjf = TRUE;
        opt->test_np_priority = TRUE;
        opt->test_p_priority = TRUE;
        opt->test_rr = TRUE;
        opt->test_np_srtf = TRUE;
        opt->test_p_srtf = TRUE;
    }
}
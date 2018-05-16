#include "option.h"

#define TRUE 1
#define FALSE 0

#define DEFAULT_NUM_PROCESS 10
#define DEFAULT_TIME_QUANTUM 4

void parse_option (int argc, char ** argv, option_t * opt) {
    if (argc == 1) {
        // no argument default
        opt->test_fcfs = TRUE;
        opt->test_np_sjf = TRUE;
        opt->test_p_sjf = TRUE;
        opt->test_np_priority = TRUE;
        opt->test_p_priority = TRUE;
        opt->test_rr = TRUE;
        opt->num_of_processes = DEFAULT_NUM_PROCESS;
        opt->round_robin_time_quantum = DEFAULT_TIME_QUANTUM;
        return;
    }

    for (int i = 1; i < argc; i++) {
        
    }
}
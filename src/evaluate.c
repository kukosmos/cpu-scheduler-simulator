#include <stdio.h>

#include "evaluate.h"

double evaluate_turn_around_time (int n, process_t ** pl, int * rl) {
    int sum = 0;
    int tt = 0;
    for (int i = 1; i <= n; i++) {
        tt = pl[i]->termination_time - pl[i]->arrival_time + 1;
        sum = sum + tt;
        rl[pl[i]->pid] = tt;
    }
    return (double) sum / n;
}

double evaluate_waiting_time (int n, process_t ** pl, int * rl) {
    int sum = 0;
    int wt = 0;
    for (int i = 1; i <= n; i++) {
        wt = pl[i]->termination_time - pl[i]->arrival_time - pl[i]->cpu_burst_time - pl[i]->io_burst_time + 1;
        sum = sum + wt;
        rl[pl[i]->pid] = wt;
    }
    return (double) sum / n;
}

void print_list (char * desc, int n, int * list) {
    printf ("+-----+------------------+\n");
    printf ("| pid | %16s |\n", desc);
    printf ("+-----+------------------+\n");

    for (int i = 1; i <= n; i++) {
        printf ("| %3d | %16d |\n", i, list [i]);
        printf ("+-----+------------------+\n");
    }
}
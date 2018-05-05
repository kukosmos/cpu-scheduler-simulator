#include <pthread.h>
#include <stdlib.h>

#include "clock.h"

#define RUNNING 1
#define STOP 0

/* increase clk at every CLOCK_TIME
 */
#define CLOCK_TIME 50000000

/* use thread to constantly increase clk
 */
void * clocking (void * arg) {
    Clock * this = (Clock *) arg;

    unsigned int prev = 0;
    unsigned int cnt = 0;
    while (this->state) {
        prev = cnt;
        cnt = (cnt + 1) % CLOCK_TIME;
        if (prev > cnt) {
            this->clk = this->clk + 1;
        }
    }
}

Clock * create_clock () {
    Clock * c = (Clock *) malloc (sizeof (Clock));

    c->state = STOP;
    c->clk = 0;

    return c;
}

int get_time (Clock * this) {
    return this->clk;
}

void init_clock (Clock * this) {
    this->clk = 0;
}

void start_clock (Clock * this) {
    pthread_t tid;

    this->state = RUNNING;
    pthread_create (&tid, NULL, clocking, this);    // start clocking thread
    pthread_detach (tid);
}

void stop_clock (Clock * this) {
    this->state = STOP;
}

void delete_clock (Clock * this) {
    if (this->state) {
        stop_clock (this);
    }
    free (this);
}
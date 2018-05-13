#include <stdlib.h>

#include "clock.h"

clock_t * create_clock () {
    clock_t * c = (clock_t *) malloc (sizeof (clock_t));

    c->clk = 0;

    return c;
}

int get_time (clock_t * this) {
    return this->clk;
}

void init_clock (clock_t * this) {
    this->clk = 0;
}

void delete_clock (clock_t * this) {
    free (this);
}

void clocking (clock_t * this) {
    this->clk = this->clk + 1;
}
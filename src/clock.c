#include <stdlib.h>

#include "clock.h"

Clock * create_clock () {
    Clock * c = (Clock *) malloc (sizeof (Clock));

    c->clk = 0;

    return c;
}

int get_time (Clock * this) {
    return this->clk;
}

void init_clock (Clock * this) {
    this->clk = 0;
}

void delete_clock (Clock * this) {
    free (this);
}

void clocking (Clock * this) {
    this->clk = this->clk + 1;
}
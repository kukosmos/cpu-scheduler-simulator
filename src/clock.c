#include <stdlib.h>

#include "clock.h"

clk_t * create_clock () {
    clk_t * c = (clk_t *) malloc (sizeof (clk_t));

    c->clk = 0;

    return c;
}

int get_time (clk_t * this) {
    return this->clk;
}

void init_clock (clk_t * this) {
    this->clk = 0;
}

void delete_clock (clk_t * this) {
    free (this);
}

void clocking (clk_t * this) {
    this->clk = this->clk + 1;
}
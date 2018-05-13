#ifndef __CLOCK_H
#define __CLOCK_H

struct __clock {
    unsigned int clk;
};

typedef struct __clock clk_t;

/* create new clock
 */
clk_t * create_clock ();

/* return time
 */
int get_time (clk_t * clock);

/* reset clk
 */
void init_clock (clk_t * clock);

/* delete clock
 */
void delete_clock (clk_t * clock);

/* increase clk by 1
 */
void clocking (clk_t * clock);

#endif

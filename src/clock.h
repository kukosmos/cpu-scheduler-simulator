#ifndef __CLOCK_H
#define __CLOCK_H

struct __clock {
    unsigned int clk;
};

typedef struct __clock clock_t;

/* create new clock
 */
clock_t * create_clock ();

/* return time
 */
int get_time (clock_t * clock);

/* reset clk
 */
void init_clock (clock_t * clock);

/* delete clock
 */
void delete_clock (clock_t * clock);

/* increase clk by 1
 */
void clocking (clock_t * clock);

#endif

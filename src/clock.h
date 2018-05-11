#ifndef __CLOCK_H
#define __CLOCK_H

struct __clock {
    unsigned int clk;
};

typedef struct __clock Clock;

/* create new clock
 */
Clock * create_clock ();

/* return time
 */
int get_time (Clock * clock);

/* reset clk
 */
void init_clock (Clock * clock);

/* delete clock
 */
void delete_clock (Clock * clock);

/* increase clk by 1
 */
void clocking (Clock * clock);

#endif

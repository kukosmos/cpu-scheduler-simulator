#ifndef __CLOCK_H
#define __CLOCK_H

struct __clock {
    int state;
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

/* make state RUNNING
 */
void start_clock (Clock * clock);

/* make state STOP
 */
void stop_clock (Clock * clock);

/* delete clock
 */
void delete_clock (Clock * clock);

#endif

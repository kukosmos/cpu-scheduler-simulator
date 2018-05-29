#ifndef __P_SRTF_H
#define __P_SRTF_H

#include "../cpu_scheduler.h"
#include "../process.h"

/* preemptive SrTF queue is priority queue
 * shorter cpu burst remain time, higher priority
 */
void * create_p_srtf_queue ();

/* function for cpu scheduling
 * support preemption
 */
void p_srtf_scheduling (cpu_scheduler_t * cpu_scheduler);

/* p-SRTF enqueue
 */
void p_srtf_enqueue (void * queue, process_t * process);

#endif

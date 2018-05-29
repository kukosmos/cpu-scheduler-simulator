#ifndef __NP_SRTF_H
#define __NP_SRTF_H

#include "../cpu_scheduler.h"
#include "../process.h"

/* non-preemptive SRTF queue is priority queue
 * shorter cpu burst remain time, higher priority
 */
void * create_np_srtf_queue ();

/* function for cpu scheduling
 */
void np_srtf_scheduling (cpu_scheduler_t * cpu_scheduler);

/* p-SRTF enqueue
 */
void np_srtf_enqueue (void * queue, process_t * process);

#endif

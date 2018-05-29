#ifndef __SRTF_H
#define __SRTF_H

#include "../process.h"

struct __srtf_node {
    process_t * p;
    struct __srtf_node * next;
};

struct __srtf_queue {
    struct __srtf_node * head;
};

/* SRTF queue is priority queue
 * shorter cpu burst remain time, higher priority
 */
struct __srtf_queue * create_srtf_queue ();

/* SRTF enqueueu
 */
void srtf_enqueue (struct __srtf_queue * queue, process_t * process);

/* SRTF dequeue
 * return a process which has the shortest remain time
 */
process_t * srtf_dequeue (struct __srtf_queue * queue);

/* return TRUE if queue is empty
 */
int srtf_is_empty (struct __srtf_queue * queue);

#endif

#ifndef __PRIORITY_H
#define __PRIORITY_H

#include "../process.h"

struct __priority_node {
    process_t * p;
    struct __priority_node * next;
};

struct __priority_queue {
    struct __priority_node * head;
};

/* priority queue is priority queue
 * smaller priority value, higher priority
 */
struct __priority_queue * create_priority_queue ();

/* priority enqueue
 */
void priority_enqueue (struct __priority_queue * queue, process_t * process);

/* priority dequeue
 * return a process which has the minimum priority value
 */
process_t * priority_dequeue (struct __priority_queue * queue);

/* return TRUE if queue is empty
 */
int priority_is_empty (struct __priority_queue * queue);

#endif

#ifndef __RECORD_H
#define __RECORD_H

struct __record_node {
    unsigned int pid;
    struct __record_node * prev;
    struct __record_node * next;  
};

struct __record {
    int n;
    char * desc;
    struct __record_node * head;
    struct __record_node * tail;
};

typedef struct __record record_t;

/* create record
 */
record_t * create_record (char * description, int n);

/* delete record
 */
void delete_record (record_t * record);

/* write pid to and of list
 */
void write (record_t * record, int pid);

/* print gantt_chart
 */
void show_gantt_chart (record_t * record);

/* reset record
 * delete ALL nodes
 */
void reset_record (record_t * record);

#endif

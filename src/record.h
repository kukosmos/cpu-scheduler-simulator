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

typedef struct __record Record;

/* create record
 */
Record * create_record (char * description, int n);

/* delete record
 */
void delete_record (Record * record);

/* write pid to and of list
 */
void write (Record * record, int pid);

/* 
 */
void show_gantt_chart (Record * record);

#endif

#include <stdlib.h>
#include <stdio.h>

#include "record.h"

#define NODE struct __record_node

void str_cp (char * orig, char * targ) {
    while (*orig != 0) {
        *targ = *orig;
        orig++;
        targ++;
    }
}

void delete_node (NODE * del) {
    if (del->next != NULL) {
        delete_node (del->next);
    }
    free (del);
}

record_t * create_record (char * description, int n) {
    record_t * r = (record_t *) malloc (sizeof (record_t));
    r->n = 0;
    r->desc = (char *) malloc (sizeof (char) * n);
    str_cp (description, r->desc);
    r->head = NULL;
    r->tail = NULL;
    return r;
}

void delete_record (record_t * this) {
    if (this->head != NULL) {
        delete_node (this->head);
    }
    free (this);
}

void write (record_t * this, int pid) {
    NODE * n = (NODE *) malloc (sizeof (NODE));
    n->pid = pid;
    n->prev = this->tail;
    if (this->tail != NULL) {
        this->tail->next = n;
    }
    n->next = NULL;
    if (this->head == NULL) {
        this->head = n;
    }
    this->tail = n;
}

void show_gantt_chart (record_t * this) {
    NODE * temp = this->head;
    int time = 0;
    printf ("%3d0----+----+----+----+----5----+----+----+----+----+\n   ", time / 10);
    while (temp != NULL) {
        printf ("| %2d ", temp->pid);
        temp = temp->next;
        time++;
        if (!(time % 10)) {
            printf ("|\n");
            printf ("%3d0----+----+----+----+----5----+----+----+----+----+\n   ", time / 10);
        }
    }
    if (time % 10 != 0) {
        printf ("|\n   ");
        for (int i = 0; i < time % 10; i++) {
            printf ("+----");
        } 
        printf ("+\n");
    }
    printf ("\n");
}

void reset_record (record_t * this) {
    if (this->head != NULL) {
        delete_node (this->head);
    }
    this->head = NULL;
    this->tail = NULL;
}

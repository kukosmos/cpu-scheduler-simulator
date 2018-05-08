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

Record * create_record (char * description, int n) {
    Record * r = (Record *) malloc (sizeof (Record));
    r->n = 0;
    r->desc = (char *) malloc (sizeof (char) * n);
    str_cp (description, r->desc);
    r->head = NULL;
    r->tail = NULL;
    return r;
}

void delete_record (Record * this) {
    if (this->head != NULL) {
        delete_node (this->head);
    }
    free (this);
}

void write (Record * this, int pid) {
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

void show_gantt_chart (Record * this) {
    NODE * temp = this->head;
    int time = 0;
    while (temp != NULL) {
        printf("%c %2d ", time % 5 == 0 ? time % 10 + '0' : '|', temp->pid);
        temp = temp->next;
        time++;
    }
    printf("|\n");
}

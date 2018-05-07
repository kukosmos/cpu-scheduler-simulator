#ifndef __RECORD_H
#define __RECORD_H

struct __record {

};

typedef struct __record Record;

Record * create_record (char * description, int n);

void delete_record (Record * record);

void write (Record * record, int pid);

#endif

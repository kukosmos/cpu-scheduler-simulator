#include <stdlib.h>

#include "cpu.h"

CPU * create_cpu (Clock * clk) {
    CPU * cpu = (CPU *) malloc (sizeof (CPU));
    cpu->clk = clk;
    cpu->record = create_record ("CPU execution log", 18);
    
    return cpu;
}

void delete_cpu (CPU * this) {
    delete_record (this->record);
    free (this);
}

void running (CPU * this) {
    if (this->process == NULL) {
        write (this->record, 0);
        return;
    }
    write (this->record, this->process->pid);
    if (run (this->process)) {
        this->process = NULL;
        return;
    }
    if (this->process->io_start_time == this->process->cpu_burst_time - this->process->cpu_remain_time) {
        io_request (this->io, this->process);
        this->process = NULL;
    }
}

int is_running (CPU * this) {
    return this->process != NULL;
}

void execute (CPU * this, Process * new, Process ** orig) {
    *orig = this->process;
    this->process = new;
}

void register_io_device (CPU * this, IO_device * io) {
    this->io = io;
}
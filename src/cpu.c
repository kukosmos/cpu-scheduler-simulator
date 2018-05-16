#include <stdlib.h>

#include "cpu.h"

cpu_t * create_cpu (clk_t * clk) {
    cpu_t * cpu = (cpu_t *) malloc (sizeof (cpu_t));
    cpu->clk = clk;
    cpu->record = create_record ("CPU execution log", 18);
    
    return cpu;
}

void delete_cpu (cpu_t * this) {
    delete_record (this->record);
    free (this);
}

void running (cpu_t * this) {
    if (this->process == NULL) {
        write (this->record, 0);
        return;
    }
    write (this->record, this->process->pid);
    if (run (this->process)) {
        this->process->termination_time = get_time (this->clk);
        this->process = NULL;
        return;
    }
    if (this->process->io_start_time == this->process->cpu_burst_time - this->process->cpu_remain_time) {
        io_request (this->io, this->process);
        this->process = NULL;
    }
}

int is_running (cpu_t * this) {
    return this->process != NULL;
}

void execute (cpu_t * this, process_t * new, process_t ** orig) {
    *orig = this->process;
    this->process = new;
}

void register_io_device (cpu_t * this, io_device_t * io) {
    this->io = io;
}
CC = gcc
CFLAGS = -g -w
TARGET = simulator

SRC = src
ALGOSRC = $(SRC)/algorithm
BUILD = _build

MAIN = $(SRC)/main.c
CLEAN = *.o $(TARGET) $(BUILD)

ALGOS = fcfs.o priority.o np_priority.o p_priority.o sjf.o np_sjf.o p_sjf.o rr.o srtf.o p_srtf.o
OBJS = record.o process.o evaluate.o clock.o cpu.o io_device.o cpu_scheduler.o job_scheduler.o simulate.o option.o

all: echocompiling $(TARGET)
	@mkdir -p $(BUILD)
	@mv *.o $(BUILD)
	@echo 'done'
	@echo './simulator --help' for help

echocompiling:
	@echo 'compiling...'

debug: $(TARGET)

$(TARGET): $(OBJS) $(ALGOS)
	@$(CC) $(MAIN) -o $@ $^ $(CFLAGS)

$(OBJS): %.o: $(SRC)/%.c
	@$(CC) -c $< -o $@ $(CFLAGS)

$(ALGOS): %.o: $(ALGOSRC)/%.c
	@$(CC) -c $< -o $@ $(CFLAGS)

clean:
	@rm -f -r $(CLEAN)
	@echo 'removed'
CC = gcc
CFLAGS = -g -lpthread
TARGET = run

SRC = src
ALGOSRC = src/algorithm
BUILD = _build

MAIN = $(SRC)/main.c
CLEAN = *.o $(TARGET) $(BUILD)

ALGOS = fcfs.o np_priority.o p_priority.o np_sjf.o p_sjf.o rr.o
OBJS = process.o clock.o cpu.o io_device.o cpu_scheduler.o job_scheduler.o

all: $(TARGET)
	mkdir -p $(BUILD)
	mv *.o $(BUILD)

$(TARGET): $(OBJS) $(ALGOS)
	$(CC) $(MAIN) -o $@ $^ $(CFLAGS)

$(OBJS): %.o: $(SRC)/%.c
	$(CC) -c $< -o $@

$(ALGOS): %.o: $(ALGOSRC)/%.c
	$(CC) -c $< -o $@

clean:
	rm -f -r $(CLEAN)
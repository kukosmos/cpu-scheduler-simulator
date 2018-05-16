CC = @gcc
CFLAGS = -g -w
TARGET = run

SRC = src
ALGOSRC = $(SRC)/algorithm
BUILD = _build

MAIN = $(SRC)/main.c
CLEAN = *.o $(TARGET) $(BUILD)

ALGOS = fcfs.o priority.o np_priority.o p_priority.o sjf.o np_sjf.o p_sjf.o rr.o
OBJS = record.o process.o clock.o cpu.o io_device.o cpu_scheduler.o job_scheduler.o simulate.o option.o

all: echocompiling $(TARGET)
	@mkdir -p $(BUILD)
	@mv *.o $(BUILD)
	@echo 'done'

echocompiling:
	@echo 'compiling...'

$(TARGET): $(OBJS) $(ALGOS)
	$(CC) $(MAIN) -o $@ $^ $(CFLAGS)

$(OBJS): %.o: $(SRC)/%.c
	$(CC) -c $< -o $@ $(CFLAGS)

$(ALGOS): %.o: $(ALGOSRC)/%.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	@rm -f -r $(CLEAN)
	@echo 'removed'
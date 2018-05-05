CC = gcc
TARGET = run
SRC = src
BUILD = _build

all: $(TARGET)
	mkdir $(BUILD)
	rm *.o $(BUILD)

$(TARGET):
	$(CC) $(SRC)/main.c -o $@ $^

clean:
	rm -f -r *.o $(TARGET) $(BUILD)
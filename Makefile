CC=clang
CFLAGS=-c -Wall
LDFLAGS=
SOURCE_PATH=src
BUILD_PATH=build
BIN_PATH=bin
SOURCES=src/variables.c src/lex.c src/expressions_parser.c src/main.c
OBJECTS=$(subst $(SOURCE_PATH),$(BUILD_PATH),$(SOURCES:.c=.o))
EXECUTABLE=$(BIN_PATH)/harsh
SYSTEM_PATH=/usr/local/bin

all: $(SOURCES) $(EXECUTABLE)
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
$(OBJECTS):
	$(CC) $(CFLAGS) $(subst $(BUILD_PATH),$(SOURCE_PATH),$(subst .o,.c,$@)) -o $@

run:
	$(EXECUTABLE)

install:
	cp $(EXECUTABLE) $(SYSTEM_PATH)

format:
	bin/format

clean:
	rm $(OBJECTS)
	rm $(EXECUTABLE)

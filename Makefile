CC=clang
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=src/variables.c src/lex.c src/expressions_parser.c src/main.c
OBJECTS_FILE=$(SOURCES:.c=.o)
OBJECTS=$(subst src,build,$(OBJECTS_FILE))
EXECUTABLE=bin/harsh
SYSTEM_PATH=/usr/local/bin

all: $(SOURCES) $(EXECUTABLE)
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
$(OBJECTS):
	$(CC) $(CFLAGS) $(subst build,src,$(subst .o,.c,$@)) -o $@

run:
	bin/harsh

install:
	cp $(EXECUTABLE) $(SYSTEM_PATH)

format:
	bin/format

clean:
	rm $(OBJECTS)
	rm $(EXECUTABLE)

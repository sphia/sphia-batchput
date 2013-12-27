
BIN    ?= sphia-batchput
PREFIX ?= /usr/local
SRC     = $(wildcard src/*.c)
SRC    += $(wildcard deps/*/*.c)
CFLAGS  = -std=c99 -Wall -Wextra -fPIC
CFLAGS += -fvisibility=hidden -D_BSD_SOURCE
LDFLAGS = -pthread -lsophia -Ideps

$(BIN): $(SRC)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $(BIN)

install: $(BIN)
	mkdir -p $(PREFIX)/bin
	cp $(BIN) $(PREFIX)/bin

uninstall:
	rm -f $(PREFIX)/bin/$(BIN)

.PHONY: install uninstall

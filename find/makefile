include config.mk

all: $(BIN)

$(BIN): $(OBJ)

.o:
	$(CC) $(LDFLAGS) -o $@ $(OBJ)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ): $(CONF)

clean:
	rm -rf $(BIN) $(OBJ)

.PHONY: all clean install uninstall

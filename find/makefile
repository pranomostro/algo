include config.mk

all: $(BIN)

$(BIN): $(OBJ)
$(OBJ): $(CONF)

.o:
	$(CC) $(LDFLAGS) -o $@ $(OBJ)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BIN) $(OBJ)

.PHONY: all clean

include config.mk

all: $(TARGET)

$(TARGET): $(OBJ) $(HDR)
	$(CC) $(LDFLAGS) -o $@ $(OBJ)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ): config.mk

clean:
	rm -rf $(TARGET) $(OBJ)

.PHONY: all clean

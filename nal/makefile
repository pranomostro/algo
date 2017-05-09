include config.mk

all: $(BIN)

$(BIN): $(OBJ)
$(OBJ): $(CONF)

nalgl: nalcat.o nalgl.o
	$(CC) $(LDFLAGS) nalcat.o nalgl.o -o $@
nalfg: nalcat.o nalfg.o reallocarray.o
	$(CC) $(LDFLAGS) nalcat.o nalfg.o reallocarray.o -o $@
nalns: nalcat.o nalns.o reallocarray.o
	$(CC) $(LDFLAGS) nalcat.o nalns.o reallocarray.o -o $@
nalsc: nalcat.o nalsc.o reallocarray.o
	$(CC) $(LDFLAGS) nalcat.o nalsc.o reallocarray.o -o $@

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(BIN) $(OBJ) $(BENCHFILES)

bench: $(BIN) $(BENCHFILES)
	./bench

$(BENCHFILES):
	./benchgenerate

.PHONY: all clean bench

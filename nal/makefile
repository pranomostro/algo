include config.mk

all: $(TARGET) $(OBJ)

nalgl: nalcat.o nalgl.o
	$(CC) $(LDFLAGS) nalcat.o nalgl.o -o $@
nalfg: nalcat.o nalfg.o reallocarray.o
	$(CC) $(LDFLAGS) nalcat.o nalfg.o reallocarray.o -o $@
nalns: nalcat.o nalns.o reallocarray.o
	$(CC) $(LDFLAGS) nalcat.o nalns.o reallocarray.o -o $@
nalsc: nalcat.o nalsc.o reallocarray.o
	$(CC) $(LDFLAGS) nalcat.o nalsc.o reallocarray.o -o $@

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ): $(CONF)

clean:
	rm -rf $(TARGET) $(OBJ)
	rm -rf data/change data/gen data/single

bench: $(TARGET) benchgen
	./bench

benchgen: $(BENCHFILES)

$(BENCHFILES):
	./benchgen

.PHONY: all clean bench benchgen

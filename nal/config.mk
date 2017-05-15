PREFIX=/usr/local

CC=cc

CFLAGS=-D_POSIX_C_SOURCE=200809L -Wall -Wextra -std=c99 -pedantic -O2
LDFLAGS=-s

BIN=nalfg nalgl
OBJ=$(BIN:=.o) nalcat.o reallocarray.o
CONF=config.mk nal.h

BENCHFILES= \
	data/single/20 \
	data/single/21 \
	data/single/22 \
	data/single/23 \
	data/single/24 \
	data/single/25 \
	data/single/26 \
	data/single/27 \
	data/single/28 \
	data/gen/zzz \
	data/gen/zzzz \
	data/gen/zzzzz \
	data/change/growing \
	data/change/shrinking \
	data/change/slow \
	data/change/slowdown \
	data/random/k \
	data/random/m \
	data/random/g

#configuration makefile

BENCHFILES=data/single/1 data/single/2 data/single/3 data/single/4 data/single/5 data/single/6 data/single/7 data/single/8 data/single/9 data/single/10 data/single/11 data/single/12 data/single/13 data/single/14 data/single/15 data/single/16 data/single/17 data/single/18 data/single/19 data/single/20 data/single/21 data/single/22 data/single/23 data/single/24 data/single/25 data/single/26 data/gen/zzz data/gen/zzzz data/gen/zzzzz data/change/growing data/change/shrinking

CFLAGS=-Wall -Wextra -pedantic -g
LDFLAGS=-g

TARGET=nalfg nalgl nalns nalsc
OBJ=nalcat.o nalfg.o nalgl.o nalns.o nalsc.o reallocarray.o
CONF=nal.h config.mk

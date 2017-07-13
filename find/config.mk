PREFIX=/usr/local

CC=cc

CFLAGS=-Wall -Wextra -std=c99 -pedantic -O2
LDFLAGS=-lm -s

BIN=findtest
OBJ=$(BIN:=.o) bfind1.o bfind2.o efind1.o efind2.o ffind1.o ifind1.o ifind2.o qfind1.o midcalc.o
CONF=config.mk findtest.h

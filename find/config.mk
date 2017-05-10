PREFIX=/usr/local

CC=cc

CFLAGS=-Wall -Wextra -std=c99 -pedantic -O2
LDFLAGS=-s

BIN=findtest
OBJ=$(BIN:=.o) bfind.o efind1.o ifind1.o
CONF=config.mk findtest.h

PREFIX=/usr/local

CC=cc

CFLAGS=-Wall -Wextra -std=c99 -pedantic -g
LDFLAGS=

BIN=findtest
OBJ=$(BIN:=.o) bfind.o efind1.o ifind1.o lfind.o
CONF=config.mk findtest.h

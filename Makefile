# Makefile  (simplemakefile)     (very OLD  20200124)


CFLAGS=-I. -Winvalid-pch -Wall

#CC=/usr/bin/clang -v   # see link errs with -v

CC=/usr/bin/clang 

all: rktest.exe rktest.o \
	rkdebug.o \
	perdoc.o perhtm.o  


rktest.o:    rktest.c rk.h
	$(CC) $^  $(CFLAGS)  -c

perdoc.o:    perdoc.c rk.h perdoc.h
	$(CC) $^  $(CFLAGS)  -c

perhtm.o:    perhtm.c rk.h perhtm.h
	$(CC) $^  $(CFLAGS)  -c

futdoc.o:    futdoc.c rk.h futdoc.h futdefs.h
	$(CC) $^  $(CFLAGS)  -c

futhtm.o:    futhtm.c rk.h futhtm.h futdefs.h
	$(CC) $^  $(CFLAGS)  -c

rkdebug.o:   rkdebug.c
	$(CC) $^  $(CFLAGS)  -c

rktest.exe:  rktest.o
	$(CC) $(CFLAGS) $^ -o $@

rktest.exe: rktest.o \
	rkdebug.o \
	perdoc.o perhtm.o  \
	futdoc.o futhtm.o  

# end of Makefile

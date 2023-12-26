
all:  chap6_q3.o


chap6_q3.o: chap6_q3.c
	gcc chap6_q3.c -o chap6_q3.o

clean: 
	rm *.o 

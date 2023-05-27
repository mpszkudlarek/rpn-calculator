a.out: main.c funkcje.o operacje.o bledy.o
	cc main.c funkcje.o operacje.o bledy.o
funkcje.o: funkcje.c
	cc -c funkcje.c
operacje.o: operacje.c
	cc -c operacje.c
bledy.o: bledy.c
	cc -c bledy.c

clean:
		rm -f *.o

run: a.out
		./a.out
calc: det.o menu.o main.o
	gcc -Wall -std=c99 det.o menu.o main.o -o calc

det.o: det.c header.h
	gcc -Wall -std=c99 -c det.c

menu.o: menu.c header.h
	gcc -Wall -std=c99 -c menu.c

main.o: main.c header.h
	gcc -Wall -std=c99 -c main.c

clean:
	rm *.o calc

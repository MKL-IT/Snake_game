game.exe : serpent.o init.o interface.o main.o
	gcc serpent.o init.o interface.o main.o -lgraph -o game.exe

serpent.o : serpent.c serpent.h init.h interface.h
	gcc -c serpent.c

init.o : init.c serpent.h init.h interface.h
	gcc -c init.c

interface.o : interface.c serpent.h init.h interface.h
	gcc -c interface.c

main.o : main.c interface.h
	gcc -c main.c

.PHONY : clean

clean :
	rm -f serpent.o init.o interface.o main.o

gcc = CC
BANKS = myBank.h
OBJ = myBank.o

all: Ex2

Ex2: main.o $(OBJ) libmyBank.a 
	$(CC) -Wall *.o -L. -lmyBank -o Ex2

main.o: main.c libmyBank.a
	$(CC) -Wall -c -o main.o main.c $(CFLAG)

libmyBank.a: $(OBJ) 
	ar rcs libmyBank.a $(OBJ)

myBank.o: myBank.c $(BANKS)
	$(CC) -Wall -c myBank.c -o $@

clean: 
	rm *.o *.a Ex2

.PHONY: all clean
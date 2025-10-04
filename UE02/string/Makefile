# This is a comment

CFLAGS = -std=c2x -Werror -Wall -Wpedantic
# Linker flags
LDFLAGS = 

# hängt so von main.o und str.o ab
all: main.o str.o
	gcc $(LDFLAGS) main.o str.o -o str

# -c ist nur kompilieren ohne binden
main.o: main.c
	gcc $(CFLAGS) -c main.c -o main.o

# so erkennt make was er alles neu bauen muss
str.o: str.c str.h
	gcc $(CFLAGS) -c str.c -o str.o

clean:
	del *.exe *.o
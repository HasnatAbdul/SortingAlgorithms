# code details

EXE_DIR = .
EXE = $(EXE_DIR)/main

SRC= functions.c write.c main.c sort.c generate.c

# generic build details

CC=      cc
COPT=    -O
CFLAGS=  -lm -g

# compile to  object code

OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(COPT) -c -o $@ $<

# build executable

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(EXE)

# clean up compilation

clean:
	rm -f $(OBJ) 

# dependencies
main.o:  main.c sort.h functions.h generate.h
functions.o:  functions.c sort.h functions.h
sort.o : sort.c  sort.h functions.c functions.h
generate.o: generate.c main.c sort.h
write.o: write.c write.h sort.h functions.h generate.h
CC = gcc
CFLAGS = -Wall -O2
OBJ = main.o rabbit.o population.o random_utils.o

rabbit_sim: $(OBJ)
	$(CC) $(CFLAGS) -o rabbit_sim $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o rabbit_sim

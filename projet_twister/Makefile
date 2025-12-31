CC = gcc
CFLAGS = -Wall -O2
OBJ = main.o rabbit.o population.o random_utils.o mt19937ar.o

rabbit_sim_mt: $(OBJ)
	$(CC) $(CFLAGS) -o rabbit_sim_mt $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o rabbit_sim_mt

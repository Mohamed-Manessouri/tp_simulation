CC = gcc
CFLAGS = -Wall -O2

COMMON_OBJ = rabbit.o population.o random_utils.o mt19937ar.o

rabbit_sim_mt: main.o $(COMMON_OBJ)
	$(CC) $(CFLAGS) -o rabbit_sim_mt main.o $(COMMON_OBJ)

extinction_mt: extinction_mt.o $(COMMON_OBJ)
	$(CC) $(CFLAGS) -o extinction_mt extinction_mt.o $(COMMON_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o rabbit_sim_mt extinction_mt *.dat *.png

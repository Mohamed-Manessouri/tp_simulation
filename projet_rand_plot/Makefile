CC = gcc
CFLAGS = -Wall -O2

# Fichiers objets communs
COMMON_OBJ = rabbit.o population.o random_utils.o

# Programme principal (simulation annuelle)
rabbit_sim: main.o $(COMMON_OBJ)
	$(CC) $(CFLAGS) -o rabbit_sim main.o $(COMMON_OBJ)

# Programme secondaire (étude statistique d'extinction)
extinction: extinction.o $(COMMON_OBJ)
	$(CC) $(CFLAGS) -o extinction extinction.o $(COMMON_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o rabbit_sim extinction


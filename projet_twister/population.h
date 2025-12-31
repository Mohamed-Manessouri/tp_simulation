#ifndef POPULATION_H
#define POPULATION_H

#include "rabbit.h"

typedef struct {
    Rabbit *list;
    int size;
    int capacity;
} Population;

void init_population(Population *pop);
void add_rabbit(Population *pop, Rabbit r);
void simulate_year(Population *pop);
void free_population(Population *pop);
void print_stats(Population *pop, int year);

#endif

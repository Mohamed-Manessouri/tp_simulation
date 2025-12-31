#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "population.h"
#include "mt19937ar.h"






int main(int argc, char *argv[]) {
    int years = 20;
    int seed = 1;

    if (argc >= 2) years = atoi(argv[1]);
    if (argc >= 3) seed = atoi(argv[2]);

    init_genrand(seed);

    printf("Stochastic individual-based rabbit simulation (seed=%d)\n", seed);
    printf("Year\tTotal\tFemales\tMales\n");

    Population pop;
    init_population(&pop);
    add_rabbit(&pop, create_rabbit('F'));
    add_rabbit(&pop, create_rabbit('M'));

    for (int year = 0; year <= years; year++) {
        print_stats(&pop, year);
        simulate_year(&pop);
    }

    free_population(&pop);
    return 0;
}

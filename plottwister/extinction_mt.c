#include <stdio.h>
#include <stdlib.h>
#include "population.h"
#include "mt19937ar.h"

int simulate_until_extinction(int seed) {
    init_genrand(seed);
    Population pop;
    init_population(&pop);
    add_rabbit(&pop, create_rabbit('F'));
    add_rabbit(&pop, create_rabbit('M'));

    for (int year = 0; year < 50; year++) {
        int alive = 0;
        for (int i = 0; i < pop.size; i++)
            if (pop.list[i].alive) alive++;

        if (alive == 0) {
            free_population(&pop);
            return year;
        }

        simulate_year(&pop);
    }

    free_population(&pop);
    return 50; 
}

int main() {
    FILE *f = fopen("extinction_mt.dat", "w");
    if (!f) {
        perror("Erreur création fichier extinction_mt.dat");
        return 1;
    }

    for (int s = 1; s <= 100; s++) {
        int year = simulate_until_extinction(s);
        fprintf(f, "%d\n", year);
    }

    fclose(f);
    printf("Fichier extinction_mt.dat généré.\n");
    return 0;
}

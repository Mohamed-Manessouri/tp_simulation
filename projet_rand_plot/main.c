#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "population.h"

int main(int argc, char *argv[]) {
    int years = 20;
    int seed = 1;

    if (argc >= 2) years = atoi(argv[1]);
    if (argc >= 3) seed = atoi(argv[2]);

    srand(seed);

    
    char filename[50];
    sprintf(filename, "results_seed%d.dat", seed);

    FILE *f = fopen(filename, "w");
    if (!f) {
        perror("Erreur d’ouverture du fichier de sortie");
        return 1;
    }

    fprintf(f, "# Year\tTotal\tFemales\tMales\n");

    Population pop;
    init_population(&pop);
    add_rabbit(&pop, create_rabbit('F'));
    add_rabbit(&pop, create_rabbit('M'));

    for (int year = 0; year <= years; year++) {
        
        int males = 0, females = 0, total = 0;
        for (int i = 0; i < pop.size; i++) {
            if (pop.list[i].alive) {
                total++;
                if (pop.list[i].sex == 'M') males++;
                else females++;
            }
        }

        fprintf(f, "%d\t%d\t%d\t%d\n", year, total, females, males);
        simulate_year(&pop);

        
        if (total == 0) break;
    }

    fclose(f);
    free_population(&pop);

    printf("Résultats enregistrés dans %s\n", filename);
    return 0;
}

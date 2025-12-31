#include <stdio.h>
#include <stdlib.h>
#include "population.h"
#include "random_utils.h"

#define MAX_POPULATION 100000  // limite écologique

void init_population(Population *pop) {
    pop->size = 0;
    pop->capacity = 100;
    pop->list = malloc(pop->capacity * sizeof(Rabbit));
}

void add_rabbit(Population *pop, Rabbit r) {
    if (pop->size >= pop->capacity) {
        pop->capacity *= 2;
        pop->list = realloc(pop->list, pop->capacity * sizeof(Rabbit));
    }
    pop->list[pop->size++] = r;
}

// 🔥 Nettoyage : supprime les lapins morts du tableau
void cleanup_population(Population *pop) {
    int alive_index = 0;
    for (int i = 0; i < pop->size; i++) {
        if (pop->list[i].alive) {
            pop->list[alive_index++] = pop->list[i];
        }
    }
    pop->size = alive_index;
}

void simulate_year(Population *pop) {
    int initial_size = pop->size;

    // Vieillissement + survie
    for (int i = 0; i < initial_size; i++) {
        age_rabbit(&pop->list[i]);
        survive_rabbit(&pop->list[i]);
    }

    // Reproduction (avec mortalité infantile et limite de population)
    for (int i = 0; i < initial_size; i++) {
        Rabbit *r = &pop->list[i];
        if (is_adult(r)) {
            int L = random_litters();
            for (int j = 0; j < L; j++) {
                int K = random_litter_size();
                for (int k = 0; k < K; k++) {
                    if (pop->size >= MAX_POPULATION)
                        return; // stop si trop de lapins

                    char sex = (random_uniform() < 0.5) ? 'F' : 'M';
                    Rabbit baby = create_rabbit(sex);

                    // 🔥 Mortalité infantile : 35% de survie
                    if (random_uniform() < 0.35) {
                        add_rabbit(pop, baby);
                    }
                }
            }
        }
    }

    // 🔥 Nettoyage mémoire des morts
    cleanup_population(pop);
}

void print_stats(Population *pop, int year) {
    int males = 0, females = 0, total = 0;
    for (int i = 0; i < pop->size; i++) {
        if (pop->list[i].alive) {
            total++;
            if (pop->list[i].sex == 'M') males++;
            else females++;
        }
    }
    printf("%d\t%d\t%d\t%d\n", year, total, females, males);
}

void free_population(Population *pop) {
    free(pop->list);
}

#include <stdlib.h>
#include "random_utils.h"
#include "mt19937ar.h"







double random_uniform() {
    return genrand_real2();
}

// nombre de portées par femelle (loi pondérée)
int random_litters() {
    int values[] = {3, 4, 5, 6, 7, 8, 9};
    int weights[] = {1, 2, 3, 3, 3, 2, 1};
    int total = 15;
    int r = (int)(genrand_real2() * total);
    int cumulative = 0;
    for (int i = 0; i < 7; i++) {
        cumulative += weights[i];
        if (r < cumulative)
            return values[i];
    }
    return 9;
}

// taille de portée (uniforme entre 3 et 6)
int random_litter_size() {
    int k = 3 + (int)(genrand_real2() * 4);
    return k;
}

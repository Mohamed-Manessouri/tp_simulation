#include "rabbit.h"
#include "random_utils.h"


Rabbit create_rabbit(char sex) {
    Rabbit r;
    r.age = 0;
    r.sex = sex;
    r.alive = 1;
    return r;
}




void age_rabbit(Rabbit *r) {
    if (r->alive) r->age++;
    if (r->age>15) r->alive = 0;
}



int survive_rabbit(Rabbit *r) {
    if (!r->alive) return 0;
    double p;
    if (r->age == 0) p = 0.35;
    else if (r->age <= 9) p = 0.60;
    else p = (15- r->age)*0.10;


   if (random_uniform() < p) return 1;
   r->alive = 0;
   return 0;
}



int is_adult(Rabbit *r) {
    return (r->alive && r->sex == 'F' && r->age >=1);
}



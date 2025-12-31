#ifndef RABBIT_H
#define RABBIT_H


typedef struct {
    int age;
    char sex;
    int alive;
} Rabbit;

Rabbit create_rabbit(char sex);
void age_rabbit(Rabbit *r);
int survive_rabbit(Rabbit *r);
int is_adult(Rabbit *r);

#endif

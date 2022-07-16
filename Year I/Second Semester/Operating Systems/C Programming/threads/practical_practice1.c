#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int array[100];

void *f(void *arg) {
    data d = *((data *) arg);
    printf("Thread %d waiting\n", d.id);
    pthread_barrier_wait(d.barrier);
    int copy_number = d.number;
    int current_digit;
    while(copy_number):x

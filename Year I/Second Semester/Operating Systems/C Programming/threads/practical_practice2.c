#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int id;
	int number;
	int *E, *O, *E_count, *O_count, *S;
	pthread_mutex_t *mutexes;
	pthread_barrier_t *barrier;
} data;

void *f(void *arg) {
	data d = *((data *) arg);
	printf("Thread %d waiting\n", d.id);
	pthread_barrier_wait(d.barrier);
	int copy_number = d.number;
	int current_digit;
	while(copy_number) {
		current_digit = copy_number % 10;
		copy_number /= 10;
	}
	if (current_digit % 2 == 0) {
		pthread_mutex_lock(&d.mutexes[0]);
        if (*(d.E_count) == 0) {
            printf("Thread %d added first to even array\n", d.id);
        }
		printf("Thread %d adding to even array\n", d.id);
		d.E[*(d.E_count)] = d.number;
		*(d.E_count) = *(d.E_count) + 1;
		pthread_mutex_unlock(&d.mutexes[0]);
	}
	if (current_digit % 2) {
		pthread_mutex_lock(&d.mutexes[1]);
        if (*(d.E_count) == 0) {
            printf("Thread %d added first to the odd array\n", d.id);
        }
		printf("Thread %d adding to odd array\n", d.id);
		d.O[*(d.O_count)] = d.number;
		*(d.O_count) = *(d.O_count) + 1;
		pthread_mutex_unlock(&d.mutexes[1]);
	}
    pthread_mutex_lock(&d.mutexes[2]);
     *(d.S) = *(d.S) + d.number;
    pthread_mutex_unlock(&d.mutexes[2]);
	return NULL;
}

void cleanup(pthread_t *threads, pthread_mutex_t *mutexes, data *args) {
	free(threads);
	free(mutexes);
	free(args);
}

void destroy_mutexes(pthread_mutex_t *mutexes, int count) {
	int i;
	for (i = 0; i < count; i++) {
		pthread_mutex_destroy(&mutexes[i]);
	}
}

void wait_threads(pthread_t *threads, int count) {
	int i;
	for (i = 0; i < count; i++) {
		pthread_join(threads[i], NULL);
	}
}

int main(int argc, char** argv) {
	int N;
	printf("Please insert number:");
	scanf("%d", &N);
	pthread_t *threads = malloc(N * sizeof(pthread_t));
	pthread_mutex_t *mutexes = malloc(3 * sizeof(pthread_mutex_t));
	pthread_barrier_t barrier;
	int *S = malloc(sizeof(int));
	int *E = malloc(sizeof(int) * N);
	int *O = malloc(sizeof(int) * N);
	int *E_count = malloc(sizeof(int));
	int *O_count = malloc(sizeof(int));
	*S = 0, *E_count = 0, *O_count = 0;

	data *args = malloc(N * sizeof(data));
	if (0 != pthread_barrier_init(&barrier, NULL, N)) {
		cleanup(threads, mutexes, args);
		exit(1);
	}
	int i;
	for (i = 0; i < 3; i++) {
		if (0 != pthread_mutex_init(&mutexes[i],NULL)) {
			destroy_mutexes(mutexes, i);
			cleanup(threads, mutexes, args);
			exit(1);
		}
	}
	for (i = 0; i < N; i++) {
		args[i].O = O;
		args[i].E = E;
		args[i].O_count = O_count;
		args[i].E_count = E_count;
		args[i].id = i;
		args[i].mutexes = mutexes;
		args[i].barrier = &barrier;
		args[i].S = S;
		printf("Please insert number:");
		int number;
		scanf("%d", &number);
		args[i].number = number;
		if (0 != pthread_create(&threads[i], NULL, f, (void *) &args[i])) {
			wait_threads(threads, i);
			pthread_barrier_destroy(&barrier);
			destroy_mutexes(mutexes, 3);
			cleanup(threads, mutexes, args);
			exit(1);
		}
	}

	wait_threads(threads, N);
	pthread_barrier_destroy(&barrier);
	destroy_mutexes(mutexes, 3);
	cleanup(threads, mutexes, args);
    printf("The sum is : %d\n", *S);
    printf("The size of O is : %d\n", *O_count);
    printf("The size of E is : %d\n", *E_count);
    free(S);
    free(E);
    free(O);
    free(E_count);
    free(O_count);
	return 0;
}



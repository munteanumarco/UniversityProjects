#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

typedef struct {
	int *letters, *digits, *specials;
	pthread_mutex_t *mutexes;
	char *str;
} data;

void *func(void *arg) {
	data dt = *((data*)arg);
	int l = 0, d = 0, s = 0;
	int i, len = strlen(dt.str);
	for (i = 0; i < len; i++) {
		if ((dt.str[i] >='a' && dt.str[i] <= 'z') || (dt.str[i] >='A' && dt.str[i] <= 'Z')) {
			l++;
		}
		else
			if (dt.str[i] >= '0' && dt.str[i] <= '9') {
				d++;
			}
			else
				s++;
	}

	if (l > 0) {
		pthread_mutex_lock(&dt.mutexes[0]);
		*(dt.letters) += 1;
		pthread_mutex_unlock(&dt.mutexes[0]);
	}
	if (d > 0) {
		pthread_mutex_lock(&dt.mutexes[1]);
		*(dt.digits) += 1;
                pthread_mutex_unlock(&dt.mutexes[1]);
	}
	if (s > 0) {
		pthread_mutex_lock(&dt.mutexes[2]);
		*(dt.specials) += 1;
                pthread_mutex_unlock(&dt.mutexes[2]);
	}
	return NULL;
}

int main(int argc, char **argv) {
	if (argc < 2) {
		printf("Please provide at least one argument.\n");
	}
	int *letters = malloc(sizeof(int));
	int *digits = malloc(sizeof(int));
	int *specials = malloc(sizeof(int));
	pthread_t *thrds = malloc((argc-1) * sizeof(pthread_t));
	data *args = malloc((argc - 1) * sizeof(data));
	pthread_mutex_t *mutexes = malloc(3*sizeof(pthread_mutex_t));
	int i;
	for (i = 0; i < 3; i++) {
		if( 0 > pthread_mutex_init(&mutexes[i],NULL)) {
			perror("Error on creating mutexes");
			exit(1);
		}
	}
	*letters = 0;
	*digits = 0;
	*specials = 0;
	for (i = 0; i < argc - 1; i++) {
		args[i].letters = letters;
		args[i].digits = digits;
		args[i].specials = specials;
		args[i].str = argv[i+1];
		if (0 > pthread_create(&thrds[i], NULL, func, (void*)&args[i])) {
			perror("Error on create thread");
		}
	}
	
    	for (i = 0; i < argc - 1;i++) {
       		 if (0 > pthread_join(thrds[i], NULL)) {
            		perror("Error waiting for thread");
        	 }
    	}

    	printf("Total letters: %d\nTotal digits: %d\nTotal special characters: %d\n", *letters, *digits, *specials);
    	for (i = 0; i < 3; i++) {
        	pthread_mutex_destroy(&mutexes[i]);
    	}
    	free(args);
   	free(thrds);
    	free(mutexes);
    	free(letters);
    	free(digits);
    	free(specials);
	return 0;
}

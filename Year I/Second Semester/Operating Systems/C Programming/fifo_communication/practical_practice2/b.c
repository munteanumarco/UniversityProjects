#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	int a2b;
	a2b = open("a2b", O_RDONLY);
	printf("B passed deadlock\n");
	while(1) {
		int frec[26];
		if (read(a2b, &frec, 26 * sizeof(int)) <= 0) {
			break;
		}
		int i, max = -1, letter;
		for (i = 0; i < 26; i++) {
			if (frec[i] > max) {
				max = frec[i];
				letter = i;
			}
		}
		if (letter == 23 && max == 1) {
			break;
		}
		printf("B:Most frequent letter : %c - %d times\n", letter + 'a', max);
	}
	close(a2b);
	return 0;
}

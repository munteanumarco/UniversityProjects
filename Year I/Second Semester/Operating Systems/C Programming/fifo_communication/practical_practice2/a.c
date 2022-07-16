#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	int p2a, a2p, a2b;
	p2a = open("p2a", O_RDONLY);
	a2p = open("a2p", O_WRONLY);
	a2b = open("a2b", O_WRONLY);
	printf("A passed deadlock\n");
	while(1) {
		char s[100];
		int n;
		if (read(p2a, &n, sizeof(int)) <= 0) {
			break;
		}
		if (read(p2a, s, n) <= 0) {
			break;
		}
		int frec[26] = {0}, i, sum = 0;
		for (i = 0; i < 26; i++) {
			if (s[i] >= 'a' && s[i] <= 'z') {
				frec[s[i] - 'a'] += 1;
				sum += 1;
			}
		}
		write(a2b, &frec, 26 * sizeof(int));
		if (strcmp(s,"X") == 0) {
			break;
		}
		write(a2p, &sum, sizeof(int));
	}
	close(a2b); close(p2a);
	close(a2p);
	return 0;
}

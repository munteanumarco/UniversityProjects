#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	int p2a[2], a2p[2], a2b[2];
	pipe(p2a); pipe(a2p); pipe(a2b);
	int a = fork();
	if (a == 0) {
		close(p2a[1]);close(a2b[0]);
		close(a2p[0]);
		while(1) {
			char s[100];
			int n;
			if (read(p2a[0], &n, sizeof(int)) <= 0){
				break;
			}
			if (read(p2a[0], s, n) <= 0) {
				break;
			}
			int frec[26] = {0}, i;
			for (i = 0; i < 26; i++) {
				if (s[i] >= 'a' && s[i] <= 'z') {
					frec[s[i] - 'a'] += 1;
				}
			}
			write(a2p[1], &frec, sizeof(int) * 26);
			write(a2b[1], &frec, sizeof(int) * 26);
		}
		close(a2p[1]); close(a2b[1]);
		close(p2a[0]);
		exit(0);
	}
	int b = fork();
	if (b == 0) {
		close(a2b[1]); close(p2a[0]);
		close(p2a[1]); close(a2p[0]);
		close(a2p[1]);
		while(1) {
			int frec[26];
			if (read(a2b[0], &frec, sizeof(int) * 26) <= 0) {
				break;
			}
			int sum = 0, i;
			for (i = 0; i < 26; i++) {
				sum += frec[i];
			}
			printf("B:The sum is : %d\n", sum);
		}
		close(a2b[0]);
		exit(0);
	}

	close(a2b[0]); close(a2b[1]);
	close(a2p[1]); close(p2a[0]);
	while(1) {

		char s[100];
		scanf("%s", s);
		if (strcmp(s,"X") == 0) {
			break;
		}
		int n = strlen(s) + 1;
		write(p2a[1], &n, sizeof(int));
		write(p2a[1], s, n * sizeof(char));
		int frec[26];
		if (read(a2p[0], &frec, 26 * sizeof(int)) <= 0) {
			break;
		}
		int i;
		for (i = 0; i < 26; i++) {
			printf("P:Letter %c: %d\n", 'a' + i, frec[i]);
		}
	}
	close(p2a[1]); close(a2p[0]);
	wait(0); wait(0);
	return 0;
}

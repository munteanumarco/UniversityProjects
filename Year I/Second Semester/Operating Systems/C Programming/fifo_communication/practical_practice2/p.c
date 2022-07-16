#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	int p2a, a2p;
	p2a = open("p2a", O_WRONLY);
	a2p = open("a2p", O_RDONLY);
	printf("P passed deadlock\n");
	while(1) {
		char s[100];
		scanf("%s", s);
		int n = strlen(s) + 1;
		write(p2a, &n, sizeof(int));
		write(p2a, s, n);
		int sum;
		if (read(a2p, &sum, sizeof(int)) <= 0) {
			break;
		}
		printf("P:The sum is : %d\n", sum);
		if (strcmp(s,"X") == 0) {
			break;
		}
	}
	close(p2a); close(a2p);
	return 0;
}

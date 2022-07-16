#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
int main() {
	int a2b;
	a2b = open("a2b", O_WRONLY);
	while(1) {
		char *s = (char*)malloc(100 * sizeof(char));
		scanf("%s",s);
		int n = strlen(s) + 1;
		write(a2b, &n, sizeof(int));
                write(a2b, s, n);
		if (strcmp(s,"X") == 0) {
			break;
		}
	}
	close(a2b);
	return 0;
}

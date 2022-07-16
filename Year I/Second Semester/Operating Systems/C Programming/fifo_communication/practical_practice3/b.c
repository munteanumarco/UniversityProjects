#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char** argv) {
	int a2b, b2c, n;
	a2b = open("a2b", O_RDONLY);
	b2c = open("b2c", O_WRONLY);
	while(1) {
		char *s;
		read(a2b, &n, sizeof(int));
		s = (char*)malloc(n * sizeof(char));
		read(a2b, s, n);
		int a[26] = {0};
		int i;
		for (i = 0; i < n; i++) {
			if (s[i] >= 'A' && s[i] <= 'Z') {
				s[i] = s[i] - ('A' -'a');
			}
			if (s[i] >= 'a' && s[i] <= 'z') {
				a[s[i] - 'a'] += 1;
			}
		}
		write(b2c, &a, 26 * sizeof(int));
		if (strcmp(s,"X") == 0) {
                        break;
                }
		free(s);
	}
	close(a2b);
	return 0;
}

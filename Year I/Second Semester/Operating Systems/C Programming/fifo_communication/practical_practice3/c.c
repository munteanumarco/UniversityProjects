#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	int b2c;
	b2c = open("b2c", O_RDONLY);
	while(1)
	{
		int a[26];
		read(b2c, &a, 26*sizeof(int));
		int i, sum = 0;
		for (i = 0; i < 26; i++) {
			sum += a[i];
		}
		if (sum == 1 && a[23] == 1) {
			break;
		}
		printf("The sum is : %d\n", sum);
	}
	close(b2c);
	return 0;
}

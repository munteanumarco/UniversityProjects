#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main() {
 
    int a2c, c2a;
    a2c = open("a2c", O_WRONLY);
    c2a = open("c2a", O_RDONLY);
    int i = 0;
    while(i < 5) {
        int array[6];
        printf("Please insert the six numbers\n");
        int j;
        for (j = 0; j < 6; j++) {
            scanf("%d", &array[j]);
        }
        write(a2c, &array, 6 * sizeof(int));
        i += 1;
        int guessed;
        read(c2a, &guessed, sizeof(int));
        printf("You guessed : %d\n", guessed);
    }
    close(a2c);
    close(c2a);
    return 0;
}

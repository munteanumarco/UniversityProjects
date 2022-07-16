#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main() {
 
    int b2c, c2b;
    b2c = open("b2c", O_WRONLY);
    c2b = open("c2b", O_RDONLY);
    int i = 0;
    while(i < 5) {
        int array[6];
        printf("Please insert the six numbers\n");
        int j;
        for (j = 0; j < 6; j++) {
            scanf("%d", &array[j]);
        }
        write(b2c, &array, 6 * sizeof(int));
        i += 1;
        int guessed;
        read(c2b, &guessed, sizeof(int));
        printf("You guessed : %d\n", guessed);
    }
    close(b2c);
    close(c2b);
    return 0;
}

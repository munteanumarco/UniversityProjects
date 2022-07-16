#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv) {
 
    int a2c, b2c, c2a, c2b;
    a2c = open("a2c", O_RDONLY);
    b2c = open("b2c", O_RDONLY);
    c2a = open("c2a", O_WRONLY);
    c2b = open("c2b", O_WRONLY);
    int i = 0;
    while(i < 5) {
        int array_a[6];
        int array_b[6];
        read(a2c, &array_a, 6 * sizeof(int));
        printf("Recieved from A\n");
        int j;
        int guessed_a = 0;
        for (j = 0; j < 6; j++) {
            if (array_a[j] == atoi(argv[j+1])) {
                guessed_a += 1;
            }
        }
        read(b2c, &array_b, 6 * sizeof(int));
        printf("Recieved from B\n");
        int guessed_b = 0;
        for (j = 0; j < 6; j++) {
            if (array_b[j] == atoi(argv[j+1])) {
                guessed_b += 1;
            }
        }
        write(c2a, &guessed_a, sizeof(int));
        write(c2b, &guessed_b, sizeof(int));
        i++;
    }
    close(a2c);
    close(b2c);
    close(c2a);
    close(c2b);
    return 0;
}

#include <stdio.h>

int main() {
    int x = 10;
    int y = 20;
    printf("x = %d\n", x);
    printf("y = %d\n\n", y);

    asm (
         "mr 15, %0 ;"   // r15 <- y
         "mr %0, %1 ;"   // y <- x
         "mr %1, 15   ;" // x <- r15
         : "+r"(y),"+r"(x)
    );


    printf("x = %d\n", x);
    printf("y = %d\n", y);
    return 0;
}

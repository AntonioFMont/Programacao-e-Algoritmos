#include <stdio.h>

int main() {
    int y, *p, x;
    y = 0;
    p = &y;
    x = *p;
    x = 4;
    (*p)++;
    x--;
    (*p) += x;
    printf("y = %d\n", y); // y é 4.
    return 0;
}
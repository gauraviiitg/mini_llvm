#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int main() {
    int x = 5;
    int y = 10;
    int z = add(x, y);

    for (int i = 0; i < z; ++i) {
        printf("Iteration %d\n", i + 1);
    }

    return 0;
}


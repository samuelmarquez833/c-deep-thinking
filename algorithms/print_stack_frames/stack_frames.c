#include <stdio.h>

void recursiva(int depth) {
    printf("entrando depth = %d\n", depth);

    if (depth > 0) {
        recursiva(depth - 1);
    }

    printf("saliendo  depth = %d\n", depth);
}

int main(void) {
    recursiva(3);
    return 0;
}

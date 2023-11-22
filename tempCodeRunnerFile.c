#include <stdio.h>
#include <stdarg.h>

void print_args(int count, ...) {
    va_list args1, args2;

    va_start(args1, count);

    // Make a copy of the va_list
    va_copy(args2, args1);

    // Use the original va_list
    for (int i = 0; i < count; i++) {
        printf("%d ", va_arg(args1, int));
    }
    printf("\n");

    // Use the copied va_list
    for (int i = 0; i < count; i++) {
        printf("%d ", va_arg(args2, int));
    }
    printf("\n");

    va_end(args1);
    va_end(args2);
}

int main() {
    print_args(3, 10, 20, 30);

    return 0;
}

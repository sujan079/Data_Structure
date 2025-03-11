#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c;
    int n;

    printf("Enter the Fibonacci term position (n): ");
    scanf("%d", &n);

    a = (1 + sqrt(5)) / 2;
    b = (1 - sqrt(5)) / 2;

    c = (pow(a, n) - pow(b, n)) / sqrt(5);

    printf("The %dth Fibonacci number is: %d\n", n, (int)c);

    return 0;
}


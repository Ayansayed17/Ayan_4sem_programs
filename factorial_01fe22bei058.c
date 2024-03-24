#include <stdio.h>
long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    FILE *inputFile = fopen("factorial_058.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }
    int number;
    fscanf(inputFile, "%d", &number);
    fclose(inputFile);

    long long result = factorial(number);
    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }
    fprintf(outputFile, "%lld\n", result);
    fclose(outputFile);

    printf("Factorial of %d is %lld\n", number, result);
    return 0;
}

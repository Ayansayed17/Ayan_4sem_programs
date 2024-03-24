#include <stdio.h>

void generateFibonacci(int limit) {
    int first = 0, second = 1, next;
    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        return;
    }
    fprintf(outputFile, "Fibonacci series up to %d:\n", limit);
    fprintf(outputFile, "%d, %d", first, second);
    next = first + second;
    while (next <= limit) {
        fprintf(outputFile, ", %d", next);
        first = second;
        second = next;
        next = first + second;
    }
    fclose(outputFile);
}

int main() {
    // Open the input file
    FILE *inputFile = fopen("input6.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    int limit;
    fscanf(inputFile, "%d", &limit);
    fclose(inputFile);

    generateFibonacci(limit);

    printf("Fibonacci series up to %d generated and written to output.txt.\n", limit);
    return 0;
}

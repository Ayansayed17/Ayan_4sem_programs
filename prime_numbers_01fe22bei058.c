#include <stdio.h>
int isPrime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {

    FILE *inputFile = fopen("input5.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }


    int number;
    fscanf(inputFile, "%d", &number);
    fclose(inputFile);


    int prime = isPrime(number);


    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }


    if (prime) {
        fprintf(outputFile, "%d is prime.\n", number);
    } else {
        fprintf(outputFile, "%d is not prime.\n", number);
    }
    fclose(outputFile);

    printf("Result written to output.txt.\n");
    return 0;
}

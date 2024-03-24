#include <stdio.h>

int sumOfDigits(int n) {
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    FILE *inputFile = fopen("input7.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    int number;
    fscanf(inputFile, "%d", &number);
    fclose(inputFile);

    int sum = sumOfDigits(number);

    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    fprintf(outputFile, "Sum of digits of %d is %d.\n", number, sum);
    fclose(outputFile);

    printf("Sum of digits of %d is %d. Result written to output.txt.\n", number, sum);
    return 0;
}

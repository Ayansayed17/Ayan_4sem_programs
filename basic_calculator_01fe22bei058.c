#include <stdio.h>

int main() {
    char operator;
    float num1, num2, result;
    FILE *inputFile = fopen("input11.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }
    fscanf(inputFile, "%c %f %f", &operator, &num1, &num2);
    fclose(inputFile);
    switch (operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                printf("Error! Division by zero.\n");
                return 1;
            }
            result = num1 / num2;
            break;
        default:
            printf("Error! Invalid operator.\n");
            return 1;
    }
    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }
    fprintf(outputFile, "%.2f %c %.2f = %.2f\n", num1, operator, num2, result);
    fclose(outputFile);

    printf("Result written to output.txt.\n");
    return 0;
}

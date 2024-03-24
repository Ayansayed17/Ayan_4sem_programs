#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char str1[MAX_LENGTH], str2[MAX_LENGTH], result[MAX_LENGTH * 2];

    // Open the input file
    FILE *inputFile = fopen("input13.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Read two strings from the input file
    fscanf(inputFile, "%s %s", str1, str2);
    fclose(inputFile);

    // Concatenate str2 to str1
    strcpy(result, str1);
    strcat(result, str2);

    // Copy str1 to str2
    strcpy(str2, str1);

    // Compare str1 and str2
    int comparison = strcmp(str1, str2);

    // Open the output file
    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    // Write the results to the output file
    fprintf(outputFile, "Concatenated string: %s\n", result);
    fprintf(outputFile, "Copied string: %s\n", str2);
    if (comparison == 0)
        fprintf(outputFile, "Strings are equal.\n");
    else if (comparison < 0)
        fprintf(outputFile, "String 1 is less than String 2.\n");
    else
        fprintf(outputFile, "String 1 is greater than String 2.\n");
    fclose(outputFile);

    printf("Results written to output.txt.\n");
    return 0;
}

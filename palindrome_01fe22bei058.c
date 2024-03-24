#include <stdio.h>
#include <string.h>
#include <ctype.h>
int isPalindrome(const char *str) {
    int length = strlen(str);
    for (int i = 0, j = length - 1; i < j; i++, j--) {
        if (tolower(str[i]) != tolower(str[j])) {
            return 0;
        }
    }
    return 1;
}
int main() {
    FILE *inputFile = fopen("input9.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }
    char input[100];
    fscanf(inputFile, "%s", input);
    fclose(inputFile);
    int palindrome = isPalindrome(input);
    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }
    if (palindrome) {
        fprintf(outputFile, "\"%s\" is a palindrome.\n", input);
    } else {
        fprintf(outputFile, "\"%s\" is not a palindrome.\n", input);
    }
    fclose(outputFile);

    printf("Result written to output.txt.\n");
    return 0;
}

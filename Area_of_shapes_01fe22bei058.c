#include <stdio.h>
#include <math.h>
#define PI 3.14159265
int main() {
    char shape;
    int a, b;
    FILE *inputFile = fopen("shapes_058.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");
    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening files.\n");
        return 1;
    }
    fscanf(inputFile, " %c%d%d",shape,&a,&b);
    fclose(inputFile);
    float area;
    switch (shape) {
        case 'R': area =(a)*(b);
                  break;
        case 'T': area = 0.5*(a)*(b);
                  break;
        case 'C': area = PI*(a)*(b);;
                  break;
        default:
            printf("Invalid shape type.\n");
            fclose(outputFile);
            return 1;
    }
    fprintf(outputFile, "Area of the %c is: %.2f\n", shape, area);
    fclose(outputFile);
    printf("Area of the %c is: %.2f. Result written to output.txt.\n", shape, area);
    return 0;
}

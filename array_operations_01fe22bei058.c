#include <stdio.h>
#define MAX_SIZE 100
int main() {
    int arr[MAX_SIZE];
    int size, i;
    int sum = 0;
    float average;
    int largest, smallest;
    FILE *inputFile = fopen("input12.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }
    fscanf(inputFile, "%d", &size);
    for (i = 0; i < size; i++) {
        fscanf(inputFile, "%d", &arr[i]);
        sum += arr[i];
        if (i == 0) {
            largest = smallest=arr[i];
        } else {
            if (arr[i] > largest)
                largest = arr[i];
            if (arr[i] < smallest)
                smallest = arr[i];
        }
    }
    fclose(inputFile);
    average = (float)sum / size;
    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }
    fprintf(outputFile, "Sum of the elements: %d\n", sum);
    fprintf(outputFile, "Average of the elements: %.2f\n", average);
    fprintf(outputFile, "Largest element: %d\n", largest);
    fprintf(outputFile, "Smallest element: %d\n", smallest);
    fclose(outputFile);
    printf("Results written to output.txt.\n");
    return 0;
}

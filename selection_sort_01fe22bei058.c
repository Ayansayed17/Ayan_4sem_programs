#include <stdio.h>
#define MAX_SIZE 100
void selectionSort(int arr[], int size) {
    int i, j, minIndex, temp;
    for (i = 0; i < size - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}
int main() {
    int arr[MAX_SIZE], size;
    FILE *inputFile = fopen("inputt3.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }
    fscanf(inputFile, "%d", &size);
    for (int i = 0; i < size; i++) {
        fscanf(inputFile, "%d", &arr[i]);
    }
    fclose(inputFile);
    selectionSort(arr, size);
    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }
    fprintf(outputFile, "Sorted array:\n");
    for (int i = 0; i < size; i++) {
        fprintf(outputFile, "%d ", arr[i]);
    }
    fprintf(outputFile, "\n");
    fclose(outputFile);
    printf("Sorted array written to output.txt.\n");
    return 0;
}

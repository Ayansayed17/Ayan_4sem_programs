#include <stdio.h>
#define MAX_SIZE 100
int binarySearch(int arr[], int size, int key) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int main() {
    int arr[MAX_SIZE], size, key;
    FILE *inputFile = fopen("inputt2.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }
    fscanf(inputFile, "%d", &size);
    for (int i = 0; i < size; i++) {
        fscanf(inputFile, "%d", &arr[i]);
    }
    fscanf(inputFile, "%d", &key);
    fclose(inputFile);
    int index = binarySearch(arr, size, key);
    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }
    if (index != -1) {
        fprintf(outputFile, "Element found at index: %d\n", index);
    } else {
        fprintf(outputFile, "Element not found in the array.\n");
    }
    fclose(outputFile);
    printf("Result written to output.txt.\n");
    return 0;
}

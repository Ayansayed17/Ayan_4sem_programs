#include <stdio.h>
#define MAX_SIZE 100
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main() {
    FILE *input_file, *output_file;
    int arr[MAX_SIZE], n, i;
    input_file = fopen("inputt5.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.");
        return 1;
    }
    fscanf(input_file, "%d", &n);
    for (i = 0; i < n; i++) {
        fscanf(input_file, "%d", &arr[i]);
    }
    fclose(input_file);
    insertionSort(arr, n);
    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file.");
        return 1;
    }
    fprintf(output_file, "Sorted array:\n");
    for (i = 0; i < n; i++) {
        fprintf(output_file, "%d ", arr[i]);
    }
    fclose(output_file);
    printf("Sorting completed. Check output.txt for the sorted array.\n");
    return 0;
}

#include <stdio.h>

#define MAX_SIZE 100

// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap if the element found is greater than the next element
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    FILE *input_file, *output_file;
    int arr[MAX_SIZE], n, i;

    // Open the input file
    input_file = fopen("inputt4.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.");
        return 1;
    }

    // Read the size of the array from the file
    fscanf(input_file, "%d", &n);

    // Read the elements of the array from the file
    for (i = 0; i < n; i++) {
        fscanf(input_file, "%d", &arr[i]);
    }

    // Close the input file
    fclose(input_file);

    // Perform bubble sort
    bubbleSort(arr, n);

    // Open the output file
    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file.");
        return 1;
    }

    // Write the sorted array into the output file
    fprintf(output_file, "Sorted array:\n");
    for (i = 0; i < n; i++) {
        fprintf(output_file, "%d ", arr[i]);
    }

    // Close the output file
    fclose(output_file);

    printf("Sorting completed. Check output.txt for the sorted array.\n");

    return 0;
}

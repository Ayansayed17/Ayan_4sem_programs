#include <stdio.h>
#define MAX_SIZE 100
void readMatrix(FILE *file, int matrix[MAX_SIZE][MAX_SIZE], int *rows, int *cols) {
    int i, j;
    fscanf(file, "%d %d", rows, cols);
    for (i = 0; i < *rows; i++) {
        for (j = 0; j < *cols; j++) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }
}
void writeMatrix(FILE *file, int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int i, j;
    fprintf(file, "%d %d\n", rows, cols);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            fprintf(file, "%d ", matrix[i][j]);
        }
        fprintf(file, "\n");
    }
}
void addMatrix(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}
void subtractMatrix(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}
void multiplyMatrix(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int cols2) {
    int i, j, k;
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (k = 0; k < cols1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int transposed[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}
int main() {
    FILE *input_file, *output_file;
    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE], transposed[MAX_SIZE][MAX_SIZE];
    int rows1, cols1, rows2, cols2;
    input_file = fopen("matrix1.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file for matrix 1.");
        return 1;
    }
    readMatrix(input_file, matrix1, &rows1, &cols1);
    fclose(input_file);
    input_file = fopen("matrix2.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file for matrix 2.");
        return 1;
    }
    readMatrix(input_file, matrix2, &rows2, &cols2);
    fclose(input_file);
    addMatrix(matrix1, matrix2, result, rows1, cols1);
    output_file = fopen("addition_result.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file for addition result.");
        return 1;
    }
    writeMatrix(output_file, result, rows1, cols1);
    fclose(output_file);
    subtractMatrix(matrix1, matrix2, result, rows1, cols1);
    output_file = fopen("subtraction_result.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file for subtraction result.");
        return 1;
    }
    writeMatrix(output_file, result, rows1, cols1);
    fclose(output_file);
    multiplyMatrix(matrix1, matrix2, result, rows1, cols1, cols2);
    output_file = fopen("multiplication_result.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file for multiplication result.");
        return 1;
    }
    writeMatrix(output_file, result, rows1, cols2);
    fclose(output_file);
    transposeMatrix(matrix1, transposed, rows1, cols1);
    output_file = fopen("transpose_result.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file for transpose result.");
        return 1;
    }
    writeMatrix(output_file, transposed, cols1, rows1);
    fclose(output_file);
    printf("Matrix operations completed. Check the respective output files for results.\n");
    return 0;
}

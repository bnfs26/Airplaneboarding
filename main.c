#include <stdio.h>
#include <stdlib.h>

#define MAX_SYMBOLS 50
#define NUMBER_OF_ROWS 30

// ***-***
#define NUMBER_OF_COLUMNS 6


int* scan_method();

void print_plane(int* plane, int size_of_column, int size_of_row);

// print_results();

int main() {


    int* plane = scan_method();

    print_plane(plane,NUMBER_OF_COLUMNS, NUMBER_OF_ROWS);

    free(plane);

    return 0;
}

int* scan_method() {
    char method[MAX_SYMBOLS];

    // Allocating space for a 2d array
    int *plane = (int*)malloc((NUMBER_OF_ROWS * NUMBER_OF_COLUMNS) * sizeof(int));

    // Ask user for boarding method as a .txt file
    printf("Insert Boarding Method file:\n");
    scanf("%s", method);

    // Open file
    FILE *file = fopen(method, "r");

    // Check file for error
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        free(plane);
        exit(EXIT_FAILURE);
    }
    // Scan individual numbers in file
    for (int i = 0 ; i < NUMBER_OF_ROWS ; i++) {
        for (int j = 0; j < NUMBER_OF_COLUMNS ; j++) {
            fscanf(file, "%d%*[, ]", &plane[i * NUMBER_OF_COLUMNS + j]);
        }
    }
    fclose(file);

    return plane;
}

// print plane/file for testing
void print_plane(int* plane, int size_of_column, int size_of_row) {
    // read through main array
    for (int i = 0; i < NUMBER_OF_ROWS; i++) {
        // read through individual row
        for (int j = 0; j < NUMBER_OF_COLUMNS; j++) {
            printf("%d ", plane[i * NUMBER_OF_COLUMNS + j]);
        }
        printf("\n");
    }
}

// print_results() {}

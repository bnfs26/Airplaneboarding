#include <stdio.h>
#include <stdlib.h>


//definitions
#define MAX_SYMBOLS 50
#define NUMBER_OF_ROWS 30
#define NUMBER_OF_COLUMNS 7

//functions
int** scan_method();

void print_plane(int** plane, int size_of_column, int size_of_row);

void free_plane(int** plane,int size_of_column);



int main() {


    int** plane = scan_method();

    print_plane(plane,NUMBER_OF_COLUMNS, NUMBER_OF_ROWS);

    free_plane(plane,NUMBER_OF_COLUMNS);

    return 0;
}

int** scan_method() {
    char method[MAX_SYMBOLS];

    // Allocating space for a 2d array
    int **plane = malloc(NUMBER_OF_ROWS * sizeof(int *));

    for (int i = 0; i < NUMBER_OF_ROWS; i++) {
        plane[i] = malloc(NUMBER_OF_COLUMNS * sizeof(int));
    }

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

        fscanf(file, "%d,%d,%d %d,%d,%d", &plane[i][0], &plane[i][1],
                                            &plane[i][2], &plane[i][4], &plane[i][5], &plane[i][6]);
        plane[i][3] = 0;
    }
    fclose(file);

    return plane;
}

// print plane/file for testing
void print_plane(int** plane, int size_of_column, int size_of_row) {
    // read through main array
    for (int i = 0; i < NUMBER_OF_ROWS; i++) {
        // read through individual row
        for (int j = 0; j < NUMBER_OF_COLUMNS; j++) {
            printf("%d ", plane[i][j]);
        }
        printf("\n");
    }
}

void free_plane(int** plane,int size_of_column) {
    for (int i = 0; i < size_of_column; i++) {
        free(plane[i]);
    }
    free(plane);
}
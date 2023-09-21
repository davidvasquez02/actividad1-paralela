#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

// matrix dimensions so that we dont have to pass them as
// parametersmat1[R1][C1] and mat2[R2][C2]
#define R1 50 // number of rows in Matrix-1
#define C1 50 // number of columns in Matrix-1
#define R2 50 // number of rows in Matrix-2
#define C2 50 // number of columns in Matrix-2

#define ROWS 50
#define COLS 50


void multiplyMatrix(int m1[][C1], int m2[][C2])
{
    int result[R1][C2];

    printf("Resultant Matrix is:\n");

    #pragma omp parallel for
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            result[i][j] = 0;

            for (int k = 0; k < R2; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }

            printf("%d\t", result[i][j]);
        }

        printf("\n");
    }
}

// Driver code
int main()
{

     int m1[ROWS][COLS];
    int m2[ROWS][COLS];

    // Inicializa la semilla para la generación de números aleatorios
    srand(time(NULL));


    // Llena las matrices con valores aleatorios entre 1 y 9
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            m1[i][j] = rand() % 9 + 1;
            m2[i][j] = rand() % 9 + 1;
        }
    }

    // Ahora, matriz1 y matriz2 contienen valores aleatorios entre 1 y 9

    // Puedes imprimir los valores de las matrices si lo deseas
    // Por ejemplo, imprimir los primeros 5x5 elementos de matriz1
    printf("Matriz 1:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d\t", m1[i][j]);
        }
        printf("\n");
    }

    // R1 = 4, C1 = 4 and R2 = 4, C2 = 4 (Update these
    // values in MACROs)
    //int m1[R1][C1] = { { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 9,9,9,9 }, { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 9,9,9,9  }, { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 9,9,9,9  },{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 9,9,9,9  },{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 9,9,9,9  }, { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 9,9,9,9  }, { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 9,9,9,9  }, { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 , 9,9,9,9 }, { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 9,9,9,9  } };

    //int m2[R2][C2] = { { 1, 1, 1, 2, 9, 9, 2, 9, 9 }, { 2, 2, 2, 2, 9, 9, 2, 9, 9 }, { 2, 2, 2, 2, 9, 9, 2, 9, 9 }, { 1, 1, 1, 2 , 9, 9, 2, 9, 9}, { 2, 2, 2, 2 , 9, 9, 2, 9, 9}, { 2, 2, 2, 2, 9, 9, 2, 9, 9 }, { 1, 1, 1, 2, 9, 9, 2, 9, 9 }, { 2, 2, 2, 2 , 9, 9, 2, 9, 9}, { 2, 2, 2, 2, 9, 9, 2, 9, 9 }, { 1, 1, 1, 2 , 9, 9, 2, 9, 9}, { 2, 2, 2, 2 , 9, 9, 2, 9, 9}, { 2, 2, 2, 2 , 9, 9}, { 1, 1, 1, 2 , 9, 9, 2, 9, 9}, { 2, 2, 2, 2, 9, 9, 2, 9, 9 }, { 2, 2, 2, 2 , 9, 9, 2, 9, 9}, { 2, 2, 2, 2 , 9, 9, 2, 9, 9}, { 1, 1, 1, 2 , 9, 9, 2, 9, 9}, { 2, 2, 2, 2, 9, 9, 2, 9, 9 }, { 2, 2, 2, 2 , 9, 9, 2, 9, 9}, { 2, 2, 2, 2 , 9, 9, 2, 9, 9}  };

    clock_t start_time, end_time;
    double cpu_time_used;

    // Guarda el tiempo de inicio
    start_time = clock();



    // if coloumn of m1 not equal to rows of m2
    if (C1 != R2) {
        printf("The number of columns in Matrix-1 must be "
               "equal to the number of rows in "
               "Matrix-2\n");
        printf("Please update MACROs value according to "
               "your array dimension in "
               "#define section\n");

        exit(EXIT_FAILURE);
    }

    // Function call
    multiplyMatrix(m1, m2);

     end_time = clock();

    // Calcula el tiempo transcurrido en segundos
    cpu_time_used = ((double)(end_time - start_time)) / 100000 ;

    printf("Tiempo transcurrido: %f segundos\n", cpu_time_used);


    return 0;
}

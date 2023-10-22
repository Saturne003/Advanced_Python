
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000
#define SIZE_OF 8 // for double precision
#define SEED 86456

double x[N][N], y[N][N], z[N][N];

int main() {
    int BLOCK_SIZE[] = {1, 2, 5, 10, 20, 50, 100};
    int i, j, k;
    double cpu_time_used, bandepasse = 0.0;
    clock_t start, end;
    srand(SEED);

    /*for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            x[i][j] = rand() / (double)RAND_MAX + 1.0;
            y[i][j] = rand() / (double)RAND_MAX + 1.0;
        }
    }*/

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            x[i][j] = rand() + 1.0;
            y[i][j] = rand() + 1.0;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            z[i][j] = 0.0;
        }
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                z[i][j] += x[i][k] * y[k][j];
            }
        }
    }

    /*printf("[");
    for (i = 0; i < N; i++) {
        printf("[");
        for (j = 0; j < N; j++) {
            printf("%f ", z[i][j]);
        }
        printf("], \n");
    }
    printf("] \n \n \n ");


    printf("[");
    for (i = 0; i < N; i++) {
        printf("[");
        for (j = 0; j < N; j++) {
            printf("%f ", x[i][j]);
        }
        printf("], \n");
    }
    printf("] \n \n \n ");


    printf("[");
    for (i = 0; i < N; i++) {
        printf("[");
        for (j = 0; j < N; j++) {
            printf("%f ", y[i][j]);
        }
        printf("], \n");
    }
    printf("] \n \n \n "); */

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            z[i][j] = 0.0;
        }
    }

    
    for ( int b = 0; b < 7 ; b++) {
        start = clock();
        for (int bi = 0; bi < N; bi += BLOCK_SIZE[b]) {
            for (int bj = 0; bj < N; bj += BLOCK_SIZE[b]) {
                for (int bk = 0; bk < N; bk += BLOCK_SIZE[b]) {
                    for (int i = bi; i < bi + BLOCK_SIZE[b]; i++) {
                        for (int j = bj; j < bj + BLOCK_SIZE[b]; j++) {
                            for (int k = bk; k < bk + BLOCK_SIZE[b]; k++) {
                                z[i][j] += x[i][k] * y[k][j];
                            }
                        }
                    }
                }
            }
        }
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        cpu_time_used *= 1000 ;
        bandepasse = sizeof(double) *N * N * (1000.0 / cpu_time_used) / (1024*1024);
        printf("%f \t %f \n", cpu_time_used, bandepasse);
    }


    /*printf("[");
    for (i = 0; i < N; i++) {
        printf("[");
        for (j = 0; j < N; j++) {
            printf("%f ", z[i][j]);
        }
        printf("], \n");
    }
    printf("]");*/
    return 0;
}

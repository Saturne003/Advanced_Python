#include <stdio.h>
#include "stdlib.h"
#include <time.h>

#define MAX_STRIDE 20

int main() {
    int N = 10000;  
    double mean, cpu_time_used, bandepasse = 0.0, a[N * MAX_STRIDE];
    clock_t start, end;

    for (int i = 0; i < N * MAX_STRIDE; i++)
        a[i] = rand()%100 + 1.0;  

    for (int i_stride = 1; i_stride < MAX_STRIDE+1; i_stride++)
    { 
      mean = 0.0;

      start = clock();
      for (int i = 0; i < N * i_stride; i += i_stride)
          mean += a[i];
      end = clock();

      mean /=  N;
      cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
      cpu_time_used *= 1000 ;
      bandepasse = sizeof(double) * N * (1000.0 / cpu_time_used) / (1024*1024);
  
      printf("%d\t%lf\t%f\t%f\n", i_stride, mean, cpu_time_used, bandepasse);
    }
    
    return 0;
}
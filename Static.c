#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<omp.h>

#define N 500 //matrix size
#define RUNS 10 //number of exection
#define NUM_THREADS 4 //number of threads


//Function to multiply matrices using OpenMP (static scheduling)
void multiplymatrices(int A[N][N], int B[N][N], int C[N][N]){
    #pragma omp parallel for num_threads(NUM_THREADS) schedule(static,500)
    for (int i=0; i<N; i++){
        for (int j=0; j<N;j++){
            C[i][j]=0;
            for (int k=0;k<N;k++){
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
}
int main(){

    int A[N][N],B[N][N],C[N][N];
    double total_time=0, time_taken[RUNS];
    
    //Initialize matrices with values
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            A[i][j]=1;
            B[i][j]=2;
        }
    }
    for (int run=0;run<RUNS;run++){
        double start=omp_get_wtime();
        multiplymatrices(A,B,C);
        double end=omp_get_wtime();

        time_taken[run]=end-start;
        total_time+=time_taken[run];

        printf("Run %d: Execution Time = %.5f seconds\n", run + 1, time_taken[run]);

    }
//print average execution time
printf("\nAverage Execution time (static scheduling): %.5f seconds\n", total_time/RUNS);

return 0;

}
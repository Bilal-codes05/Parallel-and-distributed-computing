#include<stdio.h>
#include<stdlib.h>
#include<time.h>


#define N 500 //matrix size 
#define RUNS 10 //number of time to execute

//funtion to multiply two matrices
void multiplymatrices(int A[N][N], int B[N][N], int C[N][N]){
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            C[i][j]=0;
            for (int k=0;k<N;k++){
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
}
int main(){

    int A[N][N],B[N][N],C[N][N];
    clock_t start,end;
    double total_time=0 ,time_taken[RUNS];

    //initialize matrices with values
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            A[i][j]=1; //fill matrix A with 1s
            B[i][j]=2; //fill matrix B with 2s
        }
    }

    //Run the multiplication 10 times
    for (int run=0;run<RUNS;run++){
        start =clock();
        multiplymatrices(A,B,C);
        end=clock();

        time_taken[run]=((double)(end-start))/  CLOCKS_PER_SEC; 
        total_time +=time_taken[run];
        printf("Run %d: Execution Time = %.5f seconds\n", run + 1, time_taken[run]);

    }

    //calculate and print average executio time
    printf("\nAverage Execution Time: %.5f seconds\n",total_time/RUNS);
    
    return 0;




}
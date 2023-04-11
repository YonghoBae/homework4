#include<stdio.h>
#include<stdlib.h>

void print_matrix(int **A,int **B,int size);
void addition_matrix(int **A,int **B, int **C, int size);
void subtraction_matrix(int **A,int **B, int **C, int size);
void transpose_matrix_a(int **A, int **C, int size);
void multiply_matrix(int **A,int **B, int **C, int size);
void free_matrix(int **A,int **B, int **Add,int **Sub,int **T,int **Multi,int size);

int main(void){
    int n;
    int **A, **B, **Add, **Sub, **T, **Multi;
    printf("[----- [BaeYongho] [2020039008] -----]\n");

    scanf("%d",&n);

    A = (int**)malloc(n*sizeof(int*));
    B = (int**)malloc(n*sizeof(int*));
    Add = (int**)malloc(n*sizeof(int*));
    Sub = (int**)malloc(n*sizeof(int*));
    T = (int**)malloc(n*sizeof(int*));
    Multi = (int**)malloc(n*sizeof(int*));

    for(int i=0;i<n;i++){
        A[i] = (int*)malloc(n*sizeof(int));
        B[i] = (int*)malloc(n*sizeof(int));
        Add[i] = (int*)malloc(n*sizeof(int));
        Sub[i] = (int*)malloc(n*sizeof(int));
        T[i] = (int*)malloc(n*sizeof(int));
        Multi[i] = (int*)malloc(n*sizeof(int));
    }

    for(int j=0;j<n;j++){
        for(int k=0;k<n;k++){
            scanf("%d",&A[j][k]);
        }
        printf("\n");
    }

    for(int j=0;j<n;j++){
        for(int k=0;k<n;k++){
            scanf("%d",&B[j][k]);
        }
        printf("\n");
    }

    print_matrix(A,B,n);
    addition_matrix(A,B,Add,n);
    subtraction_matrix(A,B,Sub,n);
    transpose_matrix_a(A,T,n);
    multiply_matrix(A,B,Multi,n);
    print_matrix(Add,Sub,n);
    print_matrix(T,Multi,n);
    free_matrix(A,B,Add,Sub,T,Multi,n);
}

void print_matrix(int **A,int **B,int size){
    for(int j=0;j<size;j++){
        for(int k=0;k<size;k++){
            printf("%d ",A[j][k]);
        }
        printf("\n");
    }
    for(int j=0;j<size;j++){
        for(int k=0;k<size;k++){
            printf("%d ",B[j][k]);
        }
        printf("\n");
    }
}

void addition_matrix(int **A,int **B, int **C, int size){

    for(int j=0;j<size;j++){
        for(int k=0;k<size;k++){
            C[j][k] = A[j][k]+B[j][k];
        }
    }
}

void subtraction_matrix(int **A,int **B, int **C, int size){

    for(int j=0;j<size;j++){
        for(int k=0;k<size;k++){
            C[j][k] = A[j][k]-B[j][k];
        }
    }
}

void transpose_matrix_a(int **A,int **C, int size){

    for(int j=0;j<size;j++){
        for(int k=0;k<size;k++){
            C[j][k] = A[k][j];
        }
    }
}

void multiply_matrix(int **A,int **B, int **C, int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            C[i][j]=0;
            for(int k=0;k<size;k++){
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
}

void free_matrix(int **A,int **B, int **Add,int **Sub,int **T,int **Multi,int size){
    for(int i=0;i<size;i++){
        free(A[i]);
        free(B[i]);
        free(Add[i]);
        free(Sub[i]);
        free(T[i]);
        free(Multi[i]);
    }
    free(A);
    free(B);
    free(Add);
    free(Sub);
    free(T);
    free(Multi);
}
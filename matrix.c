#include<stdio.h>
#include<stdlib.h>

void print_matrix(int **A,int row,int column);
void addition_matrix(int **A,int **B, int **C, int row, int column);
void subtraction_matrix(int **A,int **B, int **C, int row, int column);
void transpose_matrix(int **A, int **C, int row, int column);
void multiply_matrix(int **A,int **B, int **C, int row, int column,int cr);
void free_matrix(int **C,int row);

int main(void){
    int A_row=0,A_column=0,B_row=0,B_column=0; //A,B의 행과 열 변수선언
    int **A, **B, **Add, **Sub, **T, **Multi; //A,B,합,차,전치,곱의 동적메모리할당을 받을 이중포인터 선언
    printf("[----- [BaeYongho] [2020039008] -----]\n");

    printf("A행렬의 크기를 입력해주세요.\n");
    scanf("%d %d",&A_row,&A_column);
    printf("B행렬의 크기를 입력해주세요.\n");
    scanf("%d %d",&B_row,&B_column); //A,B의 각각의 행과 열의 크기 입력

    A = (int**)malloc(A_row*sizeof(int*));
    B = (int**)malloc(B_row*sizeof(int*));
    Add = (int**)malloc(A_row*sizeof(int*));
    Sub = (int**)malloc(A_row*sizeof(int*));
    T = (int**)malloc(A_column*sizeof(int*));
    Multi = (int**)malloc(A_row*sizeof(int*)); //동적메모리할당으로 모든 행렬의 행 생성

    for(int i=0;i<A_row;i++){
        A[i] = (int*)malloc(A_column*sizeof(int));
        Add[i] = (int*)malloc(A_column*sizeof(int));
        Sub[i] = (int*)malloc(A_column*sizeof(int));
        Multi[i] = (int*)malloc(B_column*sizeof(int));
    }
    for(int i=0;i<B_row;i++)
        B[i] = (int*)malloc(B_column*sizeof(int));
    for(int i=0;i<A_column;i++)    
        T[i] = (int*)malloc(A_row*sizeof(int));//동적메모리할당으로 모든 행렬의 열 생성

    printf("A행렬의 값을 입력해주세요.\n");
    for(int j=0;j<A_row;j++){
        for(int k=0;k<A_column;k++){
            scanf("%d",&A[j][k]);
        }
    } //A의 값 입력

    printf("B행렬의 값을 입력해주세요.\n");
    for(int j=0;j<B_row;j++){
        for(int k=0;k<B_column;k++){
            scanf("%d",&B[j][k]);
        }
    } //B의 값 입력

    printf("A행렬:\n");
    print_matrix(A,A_row,A_column);
    printf("B행렬:\n");
    print_matrix(B,B_row,B_column); //A,B행렬 출력

    if(A_row==B_row && A_column==B_column){
        addition_matrix(A,B,Add,A_row,A_column);
        subtraction_matrix(A,B,Sub,A_row,A_column);
    } //A+B와 A-B가 가능하면 각각 계산
    transpose_matrix(A,T,A_column,A_row);
    if(A_column==B_row){
        multiply_matrix(A,B,Multi,A_row,B_column,A_column);
    } //A*B가 가능하면 계산
   
    if(A_row==B_row && A_column==B_column){
        printf("A+B:\n");
        print_matrix(Add,A_row,A_column);
        printf("A-B:\n");
        print_matrix(Sub,A_row,A_column);
    } //A+B와 A-B가 가능하면 각각 출력
    else{
        printf("A+B와 A-B는 불가능합니다.\n\n");
    } //A+B와 A-B가 불가능하면 해당 문자열 출력   

    printf("T:\n");
    print_matrix(T,A_column,A_row); //전치행렬 T 출력

    if(A_column==B_row){
        printf("A*B:\n");
        print_matrix(Multi,A_row,B_column);
    } //A*B가 가능하면 출력
     else{
        printf("A*B는 불가능합니다.\n\n");
    } //A*B가 불가능하면 해당 문자열출력

    free_matrix(A,A_row);
    free_matrix(B,B_row);
    free_matrix(Add,A_row);
    free_matrix(Sub,A_row);
    free_matrix(T,A_column);
    free_matrix(Multi,A_row); //할당받은 메모리 모두 해제
}

void print_matrix(int **A,int row,int column){
    for(int j=0;j<row;j++){
        for(int k=0;k<column;k++){
            printf("%d ",A[j][k]);
        }
        printf("\n");
    }
    printf("\n");
} // 매개변수로 받은 1개의 행렬 출력

void addition_matrix(int **A,int **B, int **C, int row, int column){
    for(int j=0;j<row;j++){
        for(int k=0;k<column;k++){
            C[j][k] = A[j][k]+B[j][k];
        }
    }
} // 행렬 A,B의 합 C에 대입

void subtraction_matrix(int **A,int **B, int **C, int row, int column){

    for(int j=0;j<row;j++){
        for(int k=0;k<column;k++){
            C[j][k] = A[j][k]-B[j][k];
        }
    }
} //행렬 A,B의 차 C에 대입

void transpose_matrix(int **A,int **C, int row, int column){

    for(int j=0;j<row;j++){
        for(int k=0;k<column;k++){
            C[j][k] = A[k][j];
        }
    }
} //행렬 A의 전치행렬을 C에 대입

void multiply_matrix(int **A,int **B, int **C, int row, int column,int cr){
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            C[i][j]=0;
            for(int k=0;k<cr;k++){
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
} //행렬 A,B의 곱 C에 대입

void free_matrix(int **C,int row){
    for(int i=0;i<row;i++){
        free(C[i]);
        
    }
    free(C);
} //행렬 C가 할당된 메모리 해제
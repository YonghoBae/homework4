#include<stdio.h>
#include<stdlib.h>

void print_matrix(int **A,int row,int column);
void addition_matrix(int **A,int **B, int **C, int row, int column);
void subtraction_matrix(int **A,int **B, int **C, int row, int column);
void transpose_matrix(int **A, int **C, int row, int column);
void multiply_matrix(int **A,int **B, int **C, int row, int column,int cr);
void free_matrix(int **C,int row);

int main(void){
    int A_row=0,A_column=0,B_row=0,B_column=0; //A,B�� ��� �� ��������
    int **A, **B, **Add, **Sub, **T, **Multi; //A,B,��,��,��ġ,���� �����޸��Ҵ��� ���� ���������� ����
    printf("[----- [BaeYongho] [2020039008] -----]\n");

    printf("A����� ũ�⸦ �Է����ּ���.\n");
    scanf("%d %d",&A_row,&A_column);
    printf("B����� ũ�⸦ �Է����ּ���.\n");
    scanf("%d %d",&B_row,&B_column); //A,B�� ������ ��� ���� ũ�� �Է�

    A = (int**)malloc(A_row*sizeof(int*));
    B = (int**)malloc(B_row*sizeof(int*));
    Add = (int**)malloc(A_row*sizeof(int*));
    Sub = (int**)malloc(A_row*sizeof(int*));
    T = (int**)malloc(A_column*sizeof(int*));
    Multi = (int**)malloc(A_row*sizeof(int*)); //�����޸��Ҵ����� ��� ����� �� ����

    for(int i=0;i<A_row;i++){
        A[i] = (int*)malloc(A_column*sizeof(int));
        Add[i] = (int*)malloc(A_column*sizeof(int));
        Sub[i] = (int*)malloc(A_column*sizeof(int));
        Multi[i] = (int*)malloc(B_column*sizeof(int));
    }
    for(int i=0;i<B_row;i++)
        B[i] = (int*)malloc(B_column*sizeof(int));
    for(int i=0;i<A_column;i++)    
        T[i] = (int*)malloc(A_row*sizeof(int));//�����޸��Ҵ����� ��� ����� �� ����

    printf("A����� ���� �Է����ּ���.\n");
    for(int j=0;j<A_row;j++){
        for(int k=0;k<A_column;k++){
            scanf("%d",&A[j][k]);
        }
    } //A�� �� �Է�

    printf("B����� ���� �Է����ּ���.\n");
    for(int j=0;j<B_row;j++){
        for(int k=0;k<B_column;k++){
            scanf("%d",&B[j][k]);
        }
    } //B�� �� �Է�

    printf("A���:\n");
    print_matrix(A,A_row,A_column);
    printf("B���:\n");
    print_matrix(B,B_row,B_column); //A,B��� ���

    if(A_row==B_row && A_column==B_column){
        addition_matrix(A,B,Add,A_row,A_column);
        subtraction_matrix(A,B,Sub,A_row,A_column);
    } //A+B�� A-B�� �����ϸ� ���� ���
    transpose_matrix(A,T,A_column,A_row);
    if(A_column==B_row){
        multiply_matrix(A,B,Multi,A_row,B_column,A_column);
    } //A*B�� �����ϸ� ���
   
    if(A_row==B_row && A_column==B_column){
        printf("A+B:\n");
        print_matrix(Add,A_row,A_column);
        printf("A-B:\n");
        print_matrix(Sub,A_row,A_column);
    } //A+B�� A-B�� �����ϸ� ���� ���
    else{
        printf("A+B�� A-B�� �Ұ����մϴ�.\n\n");
    } //A+B�� A-B�� �Ұ����ϸ� �ش� ���ڿ� ���   

    printf("T:\n");
    print_matrix(T,A_column,A_row); //��ġ��� T ���

    if(A_column==B_row){
        printf("A*B:\n");
        print_matrix(Multi,A_row,B_column);
    } //A*B�� �����ϸ� ���
     else{
        printf("A*B�� �Ұ����մϴ�.\n\n");
    } //A*B�� �Ұ����ϸ� �ش� ���ڿ����

    free_matrix(A,A_row);
    free_matrix(B,B_row);
    free_matrix(Add,A_row);
    free_matrix(Sub,A_row);
    free_matrix(T,A_column);
    free_matrix(Multi,A_row); //�Ҵ���� �޸� ��� ����
}

void print_matrix(int **A,int row,int column){
    for(int j=0;j<row;j++){
        for(int k=0;k<column;k++){
            printf("%d ",A[j][k]);
        }
        printf("\n");
    }
    printf("\n");
} // �Ű������� ���� 1���� ��� ���

void addition_matrix(int **A,int **B, int **C, int row, int column){
    for(int j=0;j<row;j++){
        for(int k=0;k<column;k++){
            C[j][k] = A[j][k]+B[j][k];
        }
    }
} // ��� A,B�� �� C�� ����

void subtraction_matrix(int **A,int **B, int **C, int row, int column){

    for(int j=0;j<row;j++){
        for(int k=0;k<column;k++){
            C[j][k] = A[j][k]-B[j][k];
        }
    }
} //��� A,B�� �� C�� ����

void transpose_matrix(int **A,int **C, int row, int column){

    for(int j=0;j<row;j++){
        for(int k=0;k<column;k++){
            C[j][k] = A[k][j];
        }
    }
} //��� A�� ��ġ����� C�� ����

void multiply_matrix(int **A,int **B, int **C, int row, int column,int cr){
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            C[i][j]=0;
            for(int k=0;k<cr;k++){
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
} //��� A,B�� �� C�� ����

void free_matrix(int **C,int row){
    for(int i=0;i<row;i++){
        free(C[i]);
        
    }
    free(C);
} //��� C�� �Ҵ�� �޸� ����
#include<stdio.h>
#include<stdlib.h>
//Hoang Thuy Linh - 20235135
void allocate_mem(int ***htl, int n){
    *htl = (int **) malloc (n * sizeof(int*)); // allocate rows
    if(*htl == NULL){
        return;
    }
    for(int i = 0; i < n; i++){
        (*htl)[i] = (int *) malloc(n * sizeof(int)); // allocate columns
        if((*htl)[i] == NULL) return;
    }
}
void input(int **htl, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &htl[i][j]);
        }
    }
}
void multiply(int **htl1, int **htl2, int ***result, int n){
    allocate_mem(result, n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            (*result)[i][j] = 0;
            for (int k = 0; k < n; k++){
                (*result)[i][j] += htl1[i][k] * htl2[k][j];
            }
        }
    }
}
void matrix_sum(int **htl1, int **htl2, int ***result, int n){
    allocate_mem(result, n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            (*result)[i][j] = htl1[i][j] + htl2[i][j];
        }
    }
}
void free_mem(int **htl, int n){
    for(int i = 0; i < n; i++){
        free(htl[i]);
    }
    free(htl);
}
int main(){
    int n;
    int **htl1, **htl2;
    scanf("%d", &n);
    allocate_mem(&htl1,n);
    allocate_mem(&htl2, n);
    input(htl1, n);
    input(htl2, n);
    int **result;
    multiply(htl1, htl2, &result, n);
    printf("Tich 2 ma tran:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    free_mem(result, n);
    matrix_sum(htl1, htl2, &result, n);
    printf("Tong 2 ma tran:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    free_mem(result, n);
    free_mem(htl1, n);
    free_mem(htl2, n);
    return 0;
}
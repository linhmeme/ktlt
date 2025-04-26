#include<stdio.h>
#include<stdlib.h>
//Hoang Thuy Linh - 20235135
void childArray(int *htl, int n){
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            for(int k = i; k <= j; k++){
            printf("%d ", *(htl + k));
            }
            printf("\n");
        }
    }
}

int main(){
    int n;
    int *htl;
    scanf("%d", &n);
    htl = (int *) malloc (n * sizeof(int));
    if(htl == NULL){
        printf("memory allocation failed");
        return 1;
    }
    for (int i = 0; i < n; i++){
        scanf("%d", &htl[i]);
    }
    childArray(htl, n);
    free(htl);
    return 0;
}
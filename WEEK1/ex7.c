#include<stdio.h>
#include<stdlib.h>
int *htl;
int n, tmp;
//Hoang Thuy Linh-20235135
int main(){
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    //Allocate memory
    htl = (int*) malloc (n * sizeof(int));
    if(htl == NULL){
        printf("memory allocation failed\n");
        return 1;
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &htl[i]);
    }
    printf("The input array is: \n");
    for(int i = 0; i < n; i++){
        printf("%d\n", *(htl + i));//print ra noi dung phan tu thu i
    }
    //sort array
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(*(htl + i) > *(htl + j)){
                tmp = *(htl + i);
                *(htl + i) = *(htl + j);
                *(htl + j) = tmp;
            }
        }
    }
    printf("The sorted array is: \n");
    for(int i = 0; i < n; i++){
        printf("%d\n", *(htl + i));
    }
    //free memory
    free(htl);
    return 0;
}
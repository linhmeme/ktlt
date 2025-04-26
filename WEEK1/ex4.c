#include<stdio.h>

int countEven(int *arr_htl, int size) {
    int count = 0;
    for(int i = 0; i < size; i++){
        if (arr_htl[i] % 2 == 1) count ++;
    }
    return count;
}

int main(){
    printf("Hoang Thuy Linh-20235135\n");
    int *arr, n;
    scanf("%d", &n);
    arr = (int*) malloc(n * sizeof(int)); //Cap phat bo nho cho mang arr
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int evenCount = countEven(arr, n);
    printf("Number of even numbers: %d \n", evenCount);
    free(arr);//giai phong bo nho
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
//Hoang Thuy Linh-20235135
// void reversearray(int htl[], int size){
//     int l = 0, r = size - 1, tmp;
//     while(l < r) {
//         tmp = htl[l];
//         htl[l] = htl[r];
//         htl[r] = tmp;
//         l ++;
//         r --;
//     }
// }
void ptr_reversearray(int *htl, int size){
    int *l = htl; 
    int *r = htl + size - 1; 
    int tmp;
    while(l < r) {
        tmp = *l;
        *l = *r;
        *r = tmp;
        l ++;
        r --;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    ptr_reversearray(arr, n);
    printf("reserved array: ");
    for(int i = 0; i < n; i++){
        printf("%d\n", arr[i]);
    }
    free(arr);
    return 0;
}
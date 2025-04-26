#include <stdio.h>
int main(){
    int a[7] = {13, 355, 235, 47, 67, 943, 1222};
    int *ptr_htl;
    printf("Hoang Thuy Linh-20235135");
    printf("address of first five elements in memory.\n");
    for(int i = 0; i < 5; i ++){
        ptr_htl = &a[i];
        printf("a[%d]: %p\n ", i, (void*)ptr_htl);
    }
    return 0;
}
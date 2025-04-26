#include <stdio.h>

int main(){
    int x, y, z;
    int *ptr_htl;
    printf("Hoang Thuy Linh - 20235135\n");
    printf("Enter three integers: \n");
    scanf("%d %d %d", &x, &y, &z);
    ptr_htl = &x;
    printf("x = %d\n", *ptr_htl);
    ptr_htl = &y;
    printf("y = %d\n", *ptr_htl);
    ptr_htl = &z;
    printf("z = %d\n", *ptr_htl);
    return 0;
}
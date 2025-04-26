#include<stdio.h>
int main(){
    int x, y, z;
    int *ptr_htl;
    printf("Hoang Thuy Linh-20235135");
    scanf("%d %d %d", &x, &y, &z);
    printf("Here are the values of x, y and z: \n");
    printf("%d %d %d\n", x, y, z);
    ptr_htl = &x;
    x = *ptr_htl + 100;
    ptr_htl = &y;
    y = *ptr_htl + 100;
    ptr_htl = &z;
    z = *ptr_htl + 100;
    printf("Once again, here are the values of x, y and z:\n");
    printf("%d %d %d\n", x, y, z);
    return 0;
}
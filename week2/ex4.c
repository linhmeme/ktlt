#include <stdio.h>

//Hoang Thuy Linh - 20235135
//Bài 2.4. Viết các hàm tính lập phương của số nguyên và số thực.
int cube(int x){
    return x *x *x;
}

double cube(double x){
    return x*x*x;
}

int main(){
    int n;
    double f;
    scanf("%d %lf", &n, &f);
    
    printf("Int: %d\n", cube(n));
    printf("Double: %.2lf\n", cube(f));
    
    return 0;
}
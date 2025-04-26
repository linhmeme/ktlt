#include <stdio.h>
//Hoàng Thùy Linh - 20235135 - b2 - 750828
void print(int n){
    printf("n=%d\n", n);
}

int mul3plus1(int n){
    return n * 3 + 1;
}

int div2(int n){
    return n / 2;
}
//khai báo các tham số cho các con trỏ hàm odd, even, output 
void simulate(int n, int (*odd)(int), int (*even)(int), void (*output)(int)){
    (*output)(n);
    if(n == 1) return;
    if(n % 2 == 0){
        n = (*even)(n);
    }else{
        n = (*odd)(n);
    }
    simulate(n, odd, even, output);
}

int main(){
    int (*odd)(int) = NULL;
    int (*even)(int) = NULL;
    void (*output)(int) = NULL;
    odd = &mul3plus1;
    even = &div2;
    output = &print;

    int n;
    scanf("%d", &n);
    simulate(n, odd, even, output);

    return 0;
}
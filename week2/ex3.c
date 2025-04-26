#include <stdio.h>

//Hoang Thuy Linh - 20235135 - buoi 2 - 750828
//Bài 2.3. Viết chương trình yêu cầu nhập giá trị cho số nguyên x nhỏ hơn 100. In ra giá trị ax2+bx+c  với a, b, c định sẵn.
int get_value(int x, int a, int b, int c){
    return a*x*x + b*x + c;
}

int main(){
    int x;
    scanf("%d", &x);
    
    int a = 2;
    int b = 1; 
    int c = 0;
    scanf("%d%d%d", &a, &b, &c);
    
    printf("a=2, b=1, c=0: %d\n", get_value(x, 2, 1, 0));
    printf("a=%d, b=1, c=0: %d\n", a, get_value(x, a, 1, 0));
    printf("a=%d, b=%d, c=0: %d\n", a, b, get_value(x, a, b, 0));
    printf("a=%d, b=%d, c=%d: %d\n", a, b, c, get_value(x, a, b, c));
    
    return 0;
}
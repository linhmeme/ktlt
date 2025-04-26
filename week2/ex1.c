#include <stdio.h>
#include <math.h>
/*Hoang Thuy Linh - 20235135
Bài 2.1.  Viết hàm tính độ dài cạnh huyền của tam giác theo độ hai cạnh góc vuông*/
float get_hypotenuse(float x, float y) {
    return sqrt(x*x + y*y);
}

int main() {
    float x, y;
    scanf("%f%f", &x, &y);
    
    float z = get_hypotenuse(x, y);
    printf("z = %.2f\n", z);
    
    return 0;
}
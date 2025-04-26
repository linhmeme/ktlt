#include <stdio.h>

//Hoang Thuy Linh - 20235135
//Bài 2.2. Viết hàm hoán vị vòng tròn 3 biến a, b, c. Sau khi thực hiện hàm, các biến a, b, c tương ứng nhận các giá trị mới b, c, a.
void rotate(int *x, int *y, int *z) {
    int temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}

int main(){
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    printf("Before: %d, %d, %d\n", x, y, z);
    rotate(&x, &y, &z);
    printf("After: %d, %d, %d\n", x, y, z);
    
    return 0;
}
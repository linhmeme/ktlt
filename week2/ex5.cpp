#include <iostream>
#include <ostream>
#include <math.h>
#include <iomanip>
using namespace std;

//Hoang Thuy Linh - 20235135
//Bài 2.5. Viết các toán tử tính tổng, hiệu, tích và thương của hai số phức
struct Complex{
    double real;
    double ima;
};

Complex operator + (Complex a, Complex b){
    Complex tmp;
    tmp.real = a.real + b.real;
    tmp.ima = a.ima + b.ima;
    return tmp;
}
Complex operator - (Complex a, Complex b){
    Complex tmp;
    tmp.real = a.real - b.real;
    tmp.ima = a.ima - b.ima;
    return tmp;
}
Complex operator * (Complex a, Complex b){
    Complex tmp;
    tmp.real = (a.real * b.real) - (a.ima * b.ima);
    tmp.ima = (a.real * b.ima) + (a.ima * b.real);
    return tmp;
}
Complex operator / (Complex a, Complex b){
    Complex tmp;
    double tmp1 = (b.real)*(b.real) + (b.ima)*(b.ima);
    tmp.real = (a.real * b.real) + (a.ima * b.ima);
    tmp.real /= tmp1;
    tmp.ima = (a.ima * b.real) - (a.real * b.ima);
    tmp.ima /= tmp1;
    return tmp;
}
ostream& operator << (ostream& out, const Complex &a){
    out <<'(' << std::setprecision(2) << a.real << (a.ima >= 0 ? '+' : '-')
    << std::setprecision(2) << fabs(a.ima) << 'i' <<')';
    return out;
}
int main(){
    double real_a, real_b, ima_a, ima_b;
    cin >> real_a >> ima_a;
    cin >> real_b >> ima_b;
    
    Complex a{real_a, ima_a};
    Complex b{real_b, ima_b};
    
    cout << a <<" + " << b << " = " << a + b << endl;
    cout << a <<" - " << b << " = " << a - b << endl;
    cout << a <<" * " << b << " = " << a * b << endl;
    cout << a <<" / " << b << " = " << a / b << endl;
    return 0;
}
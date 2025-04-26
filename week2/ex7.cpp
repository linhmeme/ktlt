#include <iostream>
using namespace std;
template <typename T>
//Hoàng Thùy Linh - 20235135 - b2 - 750828
T arr_sum(T *arr1, int sz1, T *arr2, int sz2){
    T sum = 0;
    for(int i = 0; i < sz1; i++){
        sum += arr1[i];
    }
    for(int i = 0; i < sz2; i++){
        sum += arr2[i];
    }
    return sum;
}
int main(){
    int val;
    cin >> val;
    {
    int a[] = {3,2,0, val};
    int b[] = {5,6,1,2,7};
    cout << arr_sum(a,4,b,5) << endl;
    }
    {
        double a[] = {3.0, 2, 0, val *1.0};
        double b[] = {5,6.1, 1, 2.3, 7};
        cout << arr_sum(a,4,b,5) << endl;
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
//Hoàng Thùy Linh - 20235135 - b2 - 750828
using namespace std;

int main(){
    int val1, val2;
    cin >> val1 >> val2;
    vector<vector<int>> a = {
        {1, 3, 7},
        {2, 3, 4, val1},
        {9, 8, 15},
        {10, val2},
    };
    //sap xep cac vector trong a theo tong cac phan tu giam dan
    auto sum = [](const vector<int> &v) -> int {
        return accumulate(v.begin(), v.end(), 0);
    };
//accumulate(trong numeric) tính tổng(cộng dồn) trên 1 dãy các phần tử trong container(vector, arr)

    sort(a.begin(), a.end(), [&](const vector<int> &v1, const vector<int> &v2) {
        return sum(v1) > sum(v2);
    });
    
    for(const auto &v : a){
        for(int it : v){
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}
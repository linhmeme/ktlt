#include <iostream>
#include <vector>
#include <algorithm>
#include <string>  // Thêm thư viện string để xử lý chữ

////Hoàng Thùy Linh - 20235135 - b2 -750828

using namespace std;

int main() {
    vector<pair<int, int>> pairs;
    string input;
    
    while (true) {
        cin >> input;
        if (input == "exit") break; // Nếu nhập exit thì dừng

        int key = stoi(input); // Chuyển input đầu tiên thành số nguyên
        int value;
        cin >> value;          // Tiếp tục nhập value

        pairs.emplace_back(key, value);
    }
    
    // Sắp xếp
    sort(pairs.begin(), pairs.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.second != b.second) 
            return a.second > b.second;
        else 
            return a.first > b.first;
    });
    
    for (auto& p : pairs) {
        cout << p.first << " " << p.second << endl;
    }
    
    return 0;
}

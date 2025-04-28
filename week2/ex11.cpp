#include <bits/stdc++.h>
using namespace std;
//Hoàng Thùy Linh - 20235135 - b2 -750828
typedef complex<double> cd;
typedef vector<cd> vcd;

// Hàm biến đổi FFT
void fft(vcd &a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * M_PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len/2; ++j) {
                cd u = a[i+j];
                cd v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert)
        for (cd &x : a)
            x /= n;
}

// Hàm nhân đa thức dùng FFT
vector<int> multiply(const vector<int> &a, const vector<int> &b) {
    vcd fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; ++i)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; ++i)
        result[i] = round(fa[i].real());

    return result;
}

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 0; i <= n; ++i)
        cin >> a[i];

    cin >> m;
    vector<int> b(m+1);
    for (int i = 0; i <= m; ++i)
        cin >> b[i];

    vector<int> c = multiply(a, b);

    int res = 0;
    for (int coeff : c)
        res ^= coeff;

    cout << res << endl;
    return 0;
}
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdio>
//Hoàng Thùy Linh - 20235135 - b2 - 750828
using namespace std;

const int LIMIT = 100;
const int NUM_ITER = 1000000;
const int NUM_INPUTS = NUM_ITER * 100;
vector<double> table; //bang look up sigmoid 

double sigmoid_slow(double x){
    return 1.0 / (1.0 + exp(-x));
}

double x[NUM_INPUTS];

void prepare_input(){
    const int PRECISION = 1000000;
    const double RANGE = LIMIT / 20.0;
    for(int i = 0; i < NUM_INPUTS; ++i){
        x[i] = RANGE * (rand() % PRECISION - rand() % PRECISION) / PRECISION;
    }
}

//begin fast code

//ham chuan bi du lieu
void precalc(){
    const double h = 0.005; //do phan giai
    const int n = 2001;//so luong phan tu(-5 den 5)
    table.resize(n);
    for(int i = 0; i < n; ++i){
        double xi = -5.0 + i *h;
        table[i] = 1.0 / (1.0 + exp(-xi));
    }
}

//ham tinh sigmoid(x) nhanh sigmoid_fast(x)
inline double sigmoid_fast(double x){
    const double scale = 200.0;//1/h = 1/0.05
    double idx = (x + 5.0) * scale;
    int i = (int)idx;
    if(i < 0) return 0.0;//qua nho
    else if(i > 2000) return 1.0;//qua lon
    else{
        double fraction = idx - i;
        return table[i] + (table[i + 1] - table[i]) * fraction;
    }
}
//end fast code
double benchmark(double (*calc)(double), vector<double> &result){
    const int NUM_TEST = 20;
    
    double taken = 0;
    result = vector<double>();
    result.reserve(NUM_ITER);

    int input_id = 0;
    clock_t start = clock();
    for(int t = 0; t < NUM_TEST; ++t){
        double sum = 0;
        for(int i = 0; i < NUM_ITER; ++i){
            double v = fabs(calc(x[input_id]));
            sum += v;
            if(t == 0) result.push_back(v);
            if((++input_id) == NUM_INPUTS) input_id = 0;
        }
    }
    clock_t finish = clock();
    taken = (double)(finish - start);
//printf("Time: %.9f\n", taken / CLOCKS_PER_SEC);
    return taken;
}

bool is_correct(const vector<double> &a, const vector<double> &b){
    const double EPS = 1e-6;
    if(a.size() != b.size()) return false;
    for(size_t i = 0; i < a.size(); ++i){
        if(fabs(a[i] - b[i]) > EPS){
            return false;
        }
    }
    return true;
}

int main(){
    prepare_input();
    precalc();

    vector<double> a, b;
    double slow = benchmark(sigmoid_slow, a);
    double fast = benchmark(sigmoid_fast, b);

    double xval;
    scanf("%lf", &xval);
    printf("%.2f\n", sigmoid_fast(xval));

    if(is_correct(a, b) && (slow/fast) > 1.3){
        printf("Correct answer! Your code is faster at least 30%%!\n");
    }else{
        printf("Wrong answer or your code is not fast enough\n");
    }
    return 0;
}
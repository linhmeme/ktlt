#include <iostream> 
#include <cmath> 
using namespace std; 
//Hoàng Thùy Linh - 20235135 - b2 -750828
struct bigNum{ 
     char sign; 
     char num[101]; 
}; 
int nho = 0; 
int maxchar = (int)'9'; 
int minchar = (int)'0'; 
int temp;

bigNum getSub(bigNum& a,bigNum& b,int& minIndex){//a>b 
    bigNum ans; 
    nho =0; 
    for(int i =100; i>=minIndex-1;i--){ 
        temp = (int)a.num[i]-(int)b.num[i]-nho; 
        if(temp<0){ 
            nho =1; 
            ans.num[i] =(char)(temp+10+minchar); 
        } 
        else{ 
            nho =0; 
            ans.num[i] =(char)(temp+minchar); 
        } 
    } 
    for(int i=0;i<minIndex;i++){
        ans.num[i]='0'; 
    } 
    return ans; 
} 

bigNum operator + (bigNum& a, bigNum& b){ 
    bigNum ans; 
    nho =0; 
    if (a.sign==b.sign){ 
        for(int i =100; i>=0;i--){ 
            if(nho==0&&a.num[i]=='0'&&b.num[i]=='0'){ 
                ans.num[i]='0'; 
                continue; 
            } 
            temp = (int)a.num[i]+(int)b.num[i]+nho- 2*minchar; 
            if(temp>=10){ 
                nho =1; 
                ans.num[i] =(char)(temp-10+minchar); 
            } 
            else{ 
                nho =0; 
                ans.num[i] =(char)(temp+minchar); 
            } 
        } 
        ans.sign=a.sign; 
        return ans; 
    } 
    else{ 
        int i =0; 
        for(;i<101;i++){ 
            if(a.num[i]!=b.num[i]) break;//min index to compare 
        } 
        if(a.num[i]<b.num[i]){ 
            ans=getSub(b,a,i); 
            ans.sign=b.sign; 
        } 
        else{ 
            ans=getSub(a,b,i); 
            ans.sign=a.sign; 
        } 
        return ans; 
    } 
} 
bigNum operator- (bigNum& a, bigNum b){ 
    if(b.sign == 1) b.sign = 0; 
    else b.sign = 1; 
    return a + b; 
} 
bigNum operator * (int x,bigNum& a){ 
    bigNum ans; 
    for(int i=0;i<101;i++) ans.num[i]='0'; 
    int lui =0; 
    while(x>=10){ 
        lui++; 
        x = x/10; 
    } 
    int mina=0; 
    for(;mina<101;mina++ ){ 
        if(a.num[mina]!='0') break; 
    } 
    nho =0; 
    mina = mina - lui-1; 
    for(int i=100;i>=mina;i--){ 
        temp = ((int)a.num[i]-minchar)*x + nho; 
        if(temp > 9){ 
            nho = temp/10; 
            temp = temp %10; 
        } 
        else nho =0; 
        ans.num[i-lui]=(char)(temp+minchar); 
    } 
    ans.sign = a.sign; 
    return ans; 
} 

bigNum  Mul (int x,bigNum& a,int lui){ 
    bigNum ans; 
    for(int i=0;i<101;i++) ans.num[i]='0'; 
    int mina=0; 
    for(;mina<101;mina++ ){ 
        if(a.num[mina]!='0') break; 
    } 
    nho =0; 
    mina = mina - lui-1; 
    for(int i=100;i>=mina;i--){ 
        temp = ((int)a.num[i]-minchar)*x + nho; 
        if(temp > 9){ 
            nho = temp/10; 
            temp = temp %10; 
        } 
        else nho =0; 
        ans.num[i-lui]=(char)(temp+minchar); 
    } 
    ans.sign = a.sign; 
    return ans; 
} 

bigNum operator * (bigNum& a, bigNum& b){ 
    bigNum ans; 
    for(int i=0;i<101;i++) ans.num[i]='0'; 
    for(int i = 100;i>=0;i--){ 
        if(a.num[i] == '0') continue; 
        bigNum H= Mul((int)a.num[i]-minchar,b,100-i); 
        ans = ans + H; 
    } 
    if(a.sign == b.sign) ans.sign='1'; 
    else ans.sign='0'; 
    return ans; 
} 

int main() { 
    bigNum a; 
    bigNum b; 
    string tmp1,tmp2; 
    getline(cin,tmp1); 
    getline(cin,tmp2); 
    a.sign = tmp1[0]; 
    temp=tmp1.length()-1; 
    for(int i=0;i<temp;i++){ 
        a.num[101-temp+i]=tmp1[i+1]; 
    } 
    temp = 100-temp; 
    for(int i = 0;i<=temp;i++){ 
        a.num[i]='0'; 
    } 
    b.sign = tmp2[0]; 
    temp=tmp2.length()-1; 
    for(int i=0;i<temp;i++){ 
        b.num[101-temp+i]=tmp2[i+1]; 
    } 
    temp = 100-temp; 
    for(int i = 0;i<=temp;i++){ 
        b.num[i]='0'; 
    }  
    bigNum A1= a*b; 
    bigNum A2= 3*a; 
    bigNum A3= 4*b;
    bigNum Ans = A1 - A2; 
    Ans = Ans + A3; 
    bool Start = false; 
    cout<<endl; 
    if(Ans.sign=='0') cout<<'-'; 
    for(int i = 0;i<101;i++){ 
        if(Ans.num[i]!='0') Start = true; 
        if(Start)   cout<<Ans.num[i]; 
    } 
} 
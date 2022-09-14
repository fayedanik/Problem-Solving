#include<bits/stdc++.h>
#define LL long long
using namespace std;
int main() {
    int tc,a,b,c,d;
    cin>>tc;
    for( int cs=1;cs<=tc;cs++ ) {
        cin>>a>>b>>c>>d;
        LL num1 = (LL) a*d, num2 = (LL) c*b;
        if( num1 == num2 )  cout << 0 << endl;
        else if( num1 == 0 || num2 == 0 || num1 % num2 == 0 || num2 % num1 == 0 )  cout << 1 << endl;
        else cout << 2 << endl;
    }
    return 0;
}
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int main() {
    LL tc,a,b,c,d;
    cin>>tc;
    for( int cs = 1; cs <= tc;cs++ ) {
        cin>>a>>b>>c>>d;
        pair<int,int>Ans ={-1,-1};
        for( int x = a+1; x <= c; x++ ) {
            LL num = a * b;
            LL s = num / __gcd(num,(LL)x);
            LL y = (d/s)*s;
            if( y <= d && y > b ) {
                Ans = {x,y};
            }
        }
        cout << Ans.first << " " << Ans.second << endl;
    }
}
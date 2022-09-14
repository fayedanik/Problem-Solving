#include<bits/stdc++.h>
#define LL long long
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    if( n==1 ) {
        cout << m << endl;
        return 0;
    }
    int ans = 1;
    for( int i = 2;;i++ ) {
        LL val = (n-1)*i;
        LL baki = m-val;
        if( baki <= 0 ) break;
        if( baki%i ==0 ) {
            ans = i;
        }
    }
    cout << ans << endl;
}
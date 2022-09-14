#include<bits/stdc++.h>
using namespace std;
int main() {
    int tc,a,b;
    cin>>tc;
    while( tc-- ) {
        cin>>a>>b;
        int ans = b*2+a+1;
        if( a==0 ) ans = 1;
        cout << ans << endl;
    }
}
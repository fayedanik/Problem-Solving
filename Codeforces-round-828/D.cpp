#include<bits/stdc++.h>
#define Lim 200005
using namespace std;

int main() {
    int tc,n;
    cin>>tc;
    while( tc-- ) {
        cin>>n;
        int d = n,x,ans=0;
        vector<int>powTwo;
        for( int i = 1;i <= n; i++ ) {
            cin>>x;
            while( !(x & 1) )  {
                x >>= 1;
                d--;
            }
            int cnt = 0,val =  i;
            while( !(val & 1) ) {
                cnt++;
                val >>= 1;
            }
            powTwo.push_back(cnt);
        }
        if( d > 0 ) {
            sort(powTwo.begin(),powTwo.end());
            reverse(powTwo.begin(),powTwo.end());
            for(auto it:powTwo) {
                d -= it;
                ans++;
                if ( d <= 0 ) break;
            }
        }

        if( d > 0 ) ans = -1;
        
        cout << ans << endl;
        
    }
}
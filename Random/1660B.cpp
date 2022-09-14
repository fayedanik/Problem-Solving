#include<bits/stdc++.h>
using namespace std;

#define lim 200005
#define LL long long

LL arr[lim];

int main() {
    LL tc,n;
    cin>>tc;
    while( tc-- ) {
        cin>>n;
        for( int i = 1; i <= n;i++ ) {
            cin>>arr[i];
        }
        sort(arr+1,arr+n+1);
        bool isPossible = true;
        for( LL i=n-1;i>=1;i-- ) {
            if( arr[i+1]-arr[i] > 1 ) {
                isPossible = false;
                break;
            } else {
                if( i-1>=1 ) {
                    arr[i] = arr[i-1];
                }
                else {
                    arr[i] = 1;
                }
            }
        }
        if( arr[1] > 1 ) isPossible = false;
        cout << (isPossible ? "YES" : "NO") << endl;
    }
}
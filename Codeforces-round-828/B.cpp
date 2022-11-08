#include<bits/stdc++.h>
#define Lim 100005
using namespace std;

int arr[Lim];

int main() {
    int n,q,tc,t,x;
    cin>>tc;
    while( tc-- ) {
        cin>>n>>q;
        int nowOdd = 0;
        long long sum = 0;
        for( int i = 1; i <= n; i++ ) {
            cin>>arr[i];
            if( arr[i] & 1 ) {
                nowOdd++;
            }
            sum += arr[i];
        }

        while( q-- ) {
            cin>>t>>x;
            if( t==1 ) {
                sum += nowOdd * x;
                if( x&1 ) {
                    nowOdd = 0;
                } 
            } else {
                sum += (n-nowOdd) * x;
                if( x&1 ) {
                    nowOdd = n;
                } 
            }
            
            cout << sum << endl;
        }
    }
}
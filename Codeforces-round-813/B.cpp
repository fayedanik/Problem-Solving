#include<bits/stdc++.h>
using namespace std;
int main() {
    int tc,n;
    cin>>tc;
    while( tc-- ) {
        cin>>n;
        if( n&1 ) {
            cout << 1 << " ";
            for( int i = 2; i <=n; i+=2 ) cout << i+1 << " " << i << " ";
        } else {
            for( int i = 1; i <=n; i+=2 ) cout << i+1 << " " << i << " ";
        }
        cout << endl;
    }
}
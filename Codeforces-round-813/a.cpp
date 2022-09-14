#include<bits/stdc++.h>
#define Lim 200005
using namespace std;

int main() {
    int tc;
    cin>>tc;
    while( tc-- ) {
        int n,k,opNeeded=0,x;
        cin>>n>>k;
        for( int i = 1; i <= n;i++ ) {
            cin>> x;
            if ( k >= i && x > k ) opNeeded++;
        }
        cout << opNeeded << endl;
    }
}
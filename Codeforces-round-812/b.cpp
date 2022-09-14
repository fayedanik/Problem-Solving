#include<bits/stdc++.h>
#define Lim 100005
using namespace std;
int arr[Lim],brr[Lim];

int main() {
    int tc,n;
    cin>>tc;
    for( int cs = 1;cs<=tc;cs++ ) {
        cin>>n;
        int idx = 0;
        for( int i = 1; i <= n; i++ ) {
            cin>> brr[i];
            if( brr[i] != brr[i-1] ) {
                arr[idx++] = brr[i];
            }
        }
        bool ans = true;
        for( int i = 1; i < idx-1; i++ ) {
            ans = ans && !(arr[i] < arr[i-1] && arr[i] < arr[i+1]); 
        }
        if( ans ) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
#include<bits/stdc++.h>
#define Lim 200005
#define LL long long
using namespace std;


int main() {
    int arr[4],ans=0,tc;
    cin>>tc;
    while( tc-- ) {
        ans = 0;
        for( int i = 0; i < 4;i++ ) cin>>arr[i];
        for( int i = 1; i < 4;i++ ) {
            ans += arr[i] < arr[0] ? 1 : 0;
        }
        cout << 3 - ans << endl;
    }
    
}
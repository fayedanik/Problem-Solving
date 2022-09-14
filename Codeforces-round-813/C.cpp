#include<bits/stdc++.h>
#define Lim 100005
using namespace std;

int arr[Lim],MAP[Lim];

int main() {
    int tc,n;
    cin>>tc;
    for( int cs = 1; cs <= tc; cs++ ) {
        cin >> n;
        for( int i = 1; i <= n; i++ ) MAP[i] = 0;
        for( int i = 1; i <= n; i++ ) {
            cin >> arr[i];
            MAP[arr[i]]++;
        }
        arr[n+1] = n+1;
        MAP[n+1]++;
        int pos = n+1;
        while( pos ) {
            int val = arr[pos];
            while( pos && val == arr[pos-1] ) {
                pos--;
                MAP[val]--;
            }
            MAP[arr[pos]]--;
            if( pos < 1 || arr[pos] < arr[pos-1] || MAP[arr[pos]] > 0 ) break;
            else {
                pos--;
            }

        }
        if( pos == 0 ) {
            cout << 0 << endl;
            continue;
        }
        int ans = pos-1;
        for( int i = 1; i < pos; i++ ) {
            if( MAP[arr[i]] ) {
                ans -= MAP[arr[i]] - 1;
                MAP[arr[i]] = 0;
            }
        }

        cout << ans << endl;
    }
}
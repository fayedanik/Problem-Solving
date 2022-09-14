#include<bits/stdc++.h>
#define Lim 200005
#define LL long long
using namespace std;

int arr[Lim],n,s;
unordered_map<int,int>MAP;
int main() {
    int tc;
    cin>>tc;
    while( tc-- ) {
        cin>>n>>s;
        int nowSum = 0;
        for( int i = 0; i < n;i++ ) {
            cin>>arr[i];
        }
        int ans = n;
        for( int i = 0; i < n;i++ ) {
            nowSum += arr[i];
            int x = nowSum - s;
            if( !x ) {
                ans = min(ans,n - i -1);
            }
            else if( MAP.find(x) != MAP.end() ) {
                ans = min(ans, MAP[x] + n - i);
            }
            if( arr[i] ) MAP[nowSum] = i;
        }
        if( ans == n ) ans = -1;
        cout << ans << endl;
        MAP.clear();
    }
}
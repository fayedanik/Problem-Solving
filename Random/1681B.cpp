#include<bits/stdc++.h>
#define Lim 200005
#define LL long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc,n,m,x;
    cin>>tc;
    while(tc--) {
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }
        cin>>m;
        vector<LL>b(m);
        for( int i=0;i<m;i++ ) {
            cin>>b[i];
        }
        LL s = accumulate(b.begin(),b.end(),0LL);
        cout << a[s%n] << '\n';
    }
}
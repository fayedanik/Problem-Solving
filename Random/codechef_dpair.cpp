#include<bits/stdc++.h>
using namespace std;
#define lim 200005
#define LL long long





int main() {
    LL n,m,x;
    cin>>n>>m;
    vector<int>u(n),v(m);
    for( int i = 0; i<n;i++ ) {
        cin>>u[i];
    }
    for( int i = 0; i<m;i++ ) {
        cin>>v[i];
    }
    int posmn = min_element(u.begin(),u.end()) - u.begin();
    int posmx = max_element(v.begin(),v.end()) - v.begin();
    for( int i = 0;i<m;i++ ) {
        cout << posmn << " " << i << endl;
    }
    for( int i = 0; i<n;i++ ) {
        if( i != posmn ) {
            cout << i << " " << posmx << endl;
        }
    }
    return 0;
}
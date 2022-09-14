#include<bits/stdc++.h>
using namespace std;
#define Lim 200005
#define LL long long

LL tree[4*Lim],nums[Lim];

void update(int nd,int b,int e,int pos) {
    if( pos > e || pos < b ) return;
    if( b == pos && e == pos) {
        tree[nd]++;
        return;
    }
    int mid = (b+e)/2;
    update(2*nd,b,mid,pos);
    update(2*nd+1,mid+1,e,pos);
    tree[nd] = tree[2*nd] + tree[2*nd+1];
}

int query(int nd,int b,int e,int i,int j) {
    if( i > e || j < b ) return 0;
    if( b>=i && e<=j ) return tree[nd];
    int mid = (b+e)/2;
    return query(2*nd,b,mid,i,j) + query(2*nd+1,mid+1,e,i,j);
}


int main() {
    int tc;
    cin>>tc;
    while( tc-- ) {
        int n;
        cin>>n;
        for(int i = 1; i<=4*n;i++ ) tree[i] = 0;
        LL ans = 0;
        for( int i = 1; i <= n; i++ ) {
            cin>>nums[i];
        }
        for( int i = n; i >= 1; i-- ) {

            if( nums[i] < i ) {
                ans += query(1,0,n,i+1,n);
                //cout << i << " " << query(1,0,n,i+1,n) << endl;
                update(1,0,n,nums[i]);
                
            } 
        }
        cout << ans << endl;
        
    }
}
#include<bits/stdc++.h>
#define Lim 200005
#define LL long long
using namespace std;

LL arr[Lim],track[Lim],tree[4*Lim];

vector<pair<int,int>>primefactrz[Lim];
set<int>st[Lim];
map<int,int>MAP[Lim];
void update(int nd,int i,int j,int pos,int val) {
    if( i>pos || j < pos ) return;
    if( i == pos && j == pos ) {
        tree[nd] = val;
        return;
    }
    int mid = (i+j)/2;
    update(2*nd,i,mid,pos,val);
    update(2*nd+1,mid+1,j,pos,val);
    tree[nd] = tree[2*nd] + tree[2*nd+1];
}

LL getSum(int nd,int b,int e,int i,int j) {
    if( i > e || j < b ) return 0;
    if( b >= i && e <= j ) return tree[nd];
    int mid = (b+e)/2;
    return getSum(2*nd,b,mid,i,j) + getSum(2*nd+1,mid+1,e,i,j);
}

void sieve() {
    for( int i = 1;i < Lim;i++ ) track[i] = i;
    for( int i = 2;i < Lim;i++ ) {
        if( track[i] == i ) {
            for( int j = i+i;j < Lim; j+=i ) {
                track[j] = i;
            }
        }
    }
}

void factorize(int N) {
    int val = N;
    while( val > 1 ) {
        int prime = track[val],cnt = 0;
        while( val > 1 && val % prime == 0 ) {
            val /= prime;
            cnt++;
        }
        primefactrz[N].push_back(make_pair(prime,cnt));
    }
}

int main() {
    sieve();
    for( int i = 2; i < Lim; i++ ) {
        factorize(i);
    }
    int n,q,t,L,R,g;
    cin>>n>>q;
    for( int i = 0;i < n;i++ ) {
        cin>>arr[i];
        for( int j = 0; j < primefactrz[arr[i]].size();j++ ) {
            pair<int,int> p = primefactrz[arr[i]][j];
            st[p.first].insert(i);
            MAP[p.first][i] = p.second;
        }
        update(1,0,n-1,i,arr[i]);
    }
    while( q-- ) {
        cin>>t>>L>>R;
        L--,R--;
        if( t == 1 ) {
            cout << getSum(1,0,n-1,L,R) << endl;
        } else {
            cin>> g;
            for( int j = 0; j < primefactrz[g].size();j++ ) {
                int prime = primefactrz[g][j].first, cnt = primefactrz[g][j].second;
                auto it = st[prime].lower_bound(L);
                while( it!=st[prime].end() && *it <= R ) {
                    update(1,0,n-1,*it,-arr[*it]);
                    int e = MAP[prime][*it],mn = min(cnt,e);
                    MAP[prime][*it] -= mn; 
                    while( mn-- ) {
                        arr[*it] /= prime;
                    }
                    update(1,0,n-1,*it,arr[*it]);
                    if( cnt >= e ) {
                        it = st[prime].erase(it);
                    } else {
                        it++;
                    }
                }
            }
        }
    }
}
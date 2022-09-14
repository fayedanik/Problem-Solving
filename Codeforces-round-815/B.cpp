#include<bits/stdc++.h>
#define Lim 100005
#define K 25
using namespace std;

int arr[Lim],tc,n,st[Lim][K][2],LOG[Lim];


void preCalculate(int N) {
    LOG[1] = 0;
    for( int i = 2; i <= N; i++ ) LOG[i] = LOG[i/2] + 1;
    for( int i = 0; i < N; i++ ) {
        st[i][0][0] = st[i][0][1] = arr[i];
    }
    for( int j = 1; j <= K; j++ ) {
        for( int i = 0; i + (1 << j) <= N; i++ ) {
            st[i][j][0] = min(st[i][j-1][0],st[i + (1 << (j-1))][j-1][0]);
            st[i][j][1] = max(st[i][j-1][1],st[i + (1 << (j-1))][j-1][1]);
        }
    }
}

int getResult( int L, int R, int type ) {
    int j = LOG[R-L+1];
    if( type == 0 ) return min(st[L][j][0],st[R-(1<<j)-1][j][0]);
    else return max(st[L][j][1],st[R-(1<<j)-1][j][1]);
}


int main() {
    int tc;
    cin>>tc;
    for( int cs=1;cs<=tc;cs++ ) {
        cin>>n;
        for( int i = 0; i < n; i++ ) {
            cin>> arr[i];
        }
        sort(arr,arr+n);
        cout << arr[n-1] + arr[n-2] - arr[1] - arr[0] << endl;
        //preCalculate(n);
    }
    return 0;
}
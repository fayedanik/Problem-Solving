#include<bits/stdc++.h>
using namespace std;

#define Lim 200005

int dp[Lim][28];

string str;

int F(int pos,int prev) {
    if( pos == str.size() ) {
        return prev ? 1 : 0;
    }
    int &ret = dp[pos][prev];
    if( ~ret ) return ret;
    ret = 2e5+10;
    if( prev ) {
        if( prev == str[pos]-'a'+1 ) {
            ret = F(pos+1,0); 
        } 
    }
    else {
        ret = min(ret,F(pos+1,str[pos]-'a'+1));
    }
    ret = min(ret,1+F(pos+1,prev));
    return ret;
}

int main() {
    int tc;
    cin>>tc;
    while( tc-- ) {
        cin>>str;
        int n = str.size();
        for( int i = 0; i <=n;i++ ) {
            for( int j=0;j<=27;j++ ) dp[i][j] = -1;
        }
        cout << F(0,0) << endl;
    }
}
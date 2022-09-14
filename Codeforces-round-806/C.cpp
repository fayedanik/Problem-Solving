#include<bits/stdc++.h>
#define Lim 105
using namespace std;

int nums[Lim];

bool isPossible(int target,int inital,string s) {
    int now = inital;
    for( int i=0; i < s.size(); i++ ) {
        if( s[i] == 'U' ) now++;
        else now--;
        if( now < 0 ) now = 9;
        if( now > 9 ) now = 0;
    }
    return now == target;
}

int main() {
    int tc,n;
    cin>>tc;
    for( int cs=1;cs<=tc;cs++ ) {
        cin>>n;
        for(int i = 1;i <= n;i++ ) cin >> nums[i];
        int k;
        string s;
        vector<int>Ans(n);
        for( int i=1;i<=n;i++ ) {
            cin>>k>>s;
            for( int pnum = 0; pnum < 10; pnum++ ) {
                if( isPossible(nums[i],pnum,s) ) {
                    Ans[i-1] = pnum;
                    break;
                }
            }
        }
        for( auto it:Ans ) cout << it << " ";
        cout << endl;
    }
    return 0;
}
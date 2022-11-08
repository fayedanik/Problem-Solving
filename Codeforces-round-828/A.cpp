#include<bits/stdc++.h>
#define Lim 51
using namespace std;

int nums[Lim],posNum[Lim];
int main() {
    int tc;
    cin>>tc;
    string str;
    for( int cs = 1; cs<=tc; cs++ ) {
        int n;
        cin>>n;
        for( int i = 1; i <= n; i++ ) {
            cin>>nums[i];
        }
        cin>>str;
        memset(posNum,-1,sizeof(posNum));
        bool isPossible = true;
        for(int i = 1; i <= n; i++ ) {
            if( ~posNum[nums[i]] ) {
                if( str[i-1] != str[posNum[nums[i]]-1] ) {
                    isPossible = false;
                    break;
                }
            }
            posNum[nums[i]] = i;
        }
        cout << (isPossible ? "YES" : "NO") << endl;
    }
    return 0;
}
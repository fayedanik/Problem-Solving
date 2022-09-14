#include<bits/stdc++.h>
using namespace std;
int main() {
    int tc;
    cin>>tc;
    for(int cs=1;cs<=tc;cs++) {
        int n;
        string s;
        cin>>n>>s;
        int freq[26];
        memset(freq,0,sizeof(freq));
        int ans = 0;
        for( int i = 0; i<n;i++ ) {
            freq[s[i]-'A']++;
            ans++;
            if( freq[s[i]-'A'] == 1 ) ans++;
        }

        cout << ans << endl;
    }
}
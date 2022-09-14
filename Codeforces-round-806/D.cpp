#include<bits/stdc++.h>
using namespace std;
int main() {
    int tc;
    cin>>tc;
    for( int cs=1;cs<=tc;cs++ ) {
        int n;
        string str;
        cin>>n;
        vector<string>v(n);
        unordered_map<string,int>MAP;
        for( int i = 0; i < n; i++ ) {
            cin>> str;
            MAP[str]++;
            v[i] = str;
        }
        string ans = "";
        for( auto x:v ) {
            string t = x;
            bool isFound = false;
            for( int j = 1; j < t.size(); j++ ) {
                string a = t.substr(0,j);
                string b = t.substr(j,t.size()-j);
                if( a.size() > 0 && b.size() > 0 && MAP[a]>0 && MAP[b]>0 ) {
                    isFound = true;
                    break;
                }
            }
            ans += isFound ? '1' : '0';
        }

        cout << ans << endl;
    }
}
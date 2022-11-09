#include<bits/stdc++.h>
using namespace std;
#define Lim 400005
int RightPos[Lim];
int main()  {
    int n,tc;
    string s;
    char c;
    cin>>tc;
    for(int cs=1;cs<=tc;cs++) {
        cin>>n>>c;
        cin>>s;
        string t = "#";
        t += s;
        t += s;
        t += "#";
        RightPos[t.size()] = -1;
        for(int i = t.size()-1; i>=0; i-- ) {
            if( t[i] == 'g' ) {
                RightPos[i] = i;
            }
            else  {
                RightPos[i] = RightPos[i+1];
            }
        }
        int minAns = 0;
        for( int i = 1; i < t.size(); i++ )  {
            if( t[i] == c && ~RightPos[i] ) {
                minAns = max(minAns,RightPos[i]-i);
            }
        }

        cout << minAns << endl;
    }

}
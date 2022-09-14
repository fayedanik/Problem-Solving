#include<bits/stdc++.h>
#define Lim 200005
#define LL long long
using namespace std;

bool isPal(int min,int sec) {
    string s = "", t = "";
    while( min ) {
        s += (min%10+'0');
        min /= 10;
    }
    while( sec ) {
        t += (sec%10+'0');
        sec /= 10;
    }
    reverse(s.begin(),s.end());
    reverse(t.begin(),t.end());
    if( s.size() == 1 ) s = '0' + s;
    if( t.size() == 1 ) t = '0' + t;
    reverse(t.begin(),t.end());
    return s==t;
}

int main() {
    int tc;
    cin>>tc;
    while(tc--) {
        string s;
        int x,ans=0;
        cin>>s>>x;
        int nowHour = (s[0]-'0')*10+(s[1]-'0'),nowMin = (s[3]-'0')*10+(s[4]-'0'),addH = x/60,addM = x%60;
        set<int>st;
        while( 1 ) {
            int totmin = nowHour*60 + nowMin;
            if( st.find(totmin) != st.end() ) break;
            st.insert(totmin);
            if( isPal(nowHour,nowMin) ) ans++;
            if( nowMin + addM > 59 ) {
                nowMin = (nowMin+addM) % 60;
                nowHour++;
            } else {
                nowMin += addM;
            }
            nowHour += addH;
            nowHour %= 24;
        }
        cout << ans << endl;
    }
}
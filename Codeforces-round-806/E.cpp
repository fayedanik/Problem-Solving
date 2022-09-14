#include<bits/stdc++.h>
using namespace std;

#define Lim 101

char str[Lim][Lim];

int main() {

    int tc;
    cin>>tc;
    for( int cs=1;cs<=tc;cs++ ) {
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) cin>>str[i][j];
        }
        int ans = 0;
        for( int i = 0; i < (n+1)/2; i++ )
        {
            int xA = i, yA = i, xB = i, yB = n - i - 1;
            int xD = n - i - 1, yD = i, xC = n - i - 1, yC = n - i -1;
            for( int rot = 1; rot < n-2*i; rot++ )
            {
                int freq[] = {0,0};
                freq[str[xA][yA]-'0']++;
                freq[str[xB][yB]-'0']++;
                freq[str[xC][yC]-'0']++;
                freq[str[xD][yD]-'0']++;
                ans += min(freq[0],freq[1]);
                yA++;
                xB++;
                yC--;
                xD--;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main() {
    int tc;
    cin>>tc;
    while( tc-- ) {
        string s;
        cin>>s;
        for( int i = 0; i < 3; i++ ) s[i] = tolower(s[i]);
        if( s == "yes" ) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}
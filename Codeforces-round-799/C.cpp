#include<bits/stdc++.h>
#define Lim 200005
#define LL long long
using namespace std;

string grid[8];

int _dx[4] = {1,1,-1,-1};
int _dy[4] = {1,-1,-1,1};

int main() {
    int tc;
    cin>>tc;
    string emptyLine;
    getline(cin,emptyLine);
    for( int cs = 1;cs<=tc;cs++ ) {
        getline(cin,emptyLine);
        for(int i = 0; i < 8;i++ ) {
            getline(cin,grid[i]);
        }
        int x = -1, y = -1;
        for( int i = 1; i < 7;i++ ) {
            for( int j = 1; j < 7;j++ ) {
                if( grid[i][j] != '#' ) continue;
                bool isFound = true;
                for( int k = 0; k < 4;k++ ) {
                    int xx = i + _dx[k];
                    int yy = j + _dy[k];
                    if( grid[xx][yy] != '#' ) {
                        isFound = false;
                        break;
                    }
                }
                if( isFound ) {
                    x = i,
                    y = j;
                    break;
                }
            }
            if( x!=-1 && y!=-1 ) break;
        }
        cout << x + 1 << " " << y + 1 << endl;
    }
}
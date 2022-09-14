#include<bits/stdc++.h>
using namespace std;
#define lim 1005
#define pii pair<int,int>

vector<pii>v;

map <pii,int>MAP;

int main() {
    int tc,n,x,y;
    cin>>tc;
    for( int cs=1;cs<=tc;cs++ ) {
        cin>>n;
        v.clear();
        MAP.clear();
        for( int i=1;i<=n;i++ ) {
            cin>>x>>y;
            MAP[make_pair(x,y)] = 1;
            v.push_back(make_pair(x,y));
        }

        for( auto item:v ) {
            bool isfound = false;
            for( int d = item.first; d <= item.second; d++ ) {
                if( item.first == item.second ) {
                    cout << item.first << " " << item.second << " " << item.second << endl;
                    break;
                }
                if( d+1 <= item.second ) {
                    if( MAP.find(make_pair(d+1,item.second))!= MAP.end() ) {
                        isfound = true;
                    }
                }
                if( d-1 >= item.first ) {
                    if( MAP.find(make_pair(item.first,d-1))!= MAP.end() ) {
                        isfound = true;
                    }
                }

                if( isfound ) {
                    cout << item.first << " " << item.second << " " << d << endl;
                    break;
                }
            }
        }
    }
}
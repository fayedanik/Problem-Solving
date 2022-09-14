#include<bits/stdc++.h>
#define Lim 100005
#define LL long long
using namespace std;

const LL Mod = 1e9 + 7;

int maxPerformance( int n,vector<int>speed,vector<int>efficieny,int k) {
    priority_queue<int,vector<int>,greater<int>>pq;
    vector<pair<int,int>>cums(n);
    for( int i = 0; i < n; i++ ) {
        cums[i] = {efficieny[i],speed[i]};
    }
    sort(cums.begin(),cums.end(),greater<pair<int,int>>());
    LL currentSum = 0,maxAns = -1;
    for( int i = 0; i < n; i++ ) {
        while( pq.size() >= k && !pq.empty() ) {
            currentSum -= pq.top();
            pq.pop();
        }
        currentSum += cums[i].second;
        LL val = (currentSum * cums[i].first ) ;
        //cout << i << " " << val << " " << pq.size() << endl;
        maxAns = max(maxAns,val);
        pq.push(cums[i].second);
        
    }
    return maxAns % Mod;
}

int main() {
    int n,k;
    cin>>n;
    vector<int>speed(n),efficiency(n);
    for( int i = 0; i < n; i++ ) cin>>speed[i];
    for( int i = 0; i < n; i++ ) cin>>efficiency[i];
    cin>>k;
    int ans = maxPerformance(n,speed,efficiency,k);
    cout << ans << endl;
}
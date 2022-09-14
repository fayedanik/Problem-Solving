#include<bits/stdc++.h>
#define Lim 200005
#define LL long long
using namespace std;

int arr[51];

int main() {
    int tc,n;
    cin>>tc;
    for( int cs=1;cs<=tc;cs++ ) {
        cin>>n;
        for(int i = 0; i < n;i++) cin>>arr[i];
        sort(arr,arr+n);
        int i = 0,j = n-1,remove=0;
        while( i<j ) {
            while( i<j && arr[i] != arr[i+1] ) i++;
            while( i<j && arr[j] != arr[j-1] ) j--;
            if( arr[i] == arr[i+1] && arr[j] == arr[j-1] ) remove += 2;
            i++,j--;
        }
        cout << n - remove << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
#define Lim 200005

int freq[Lim][3], arr[Lim];

int main()
{
    int tc, n;
    cin >> tc;
    while (tc--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            for (int j = 0; j < 2; j++){
                freq[i][j] = freq[i - 1][j];
            }
            if (abs(arr[i]) == 2)
                freq[i][0]++;
            if (arr[i] < 0)
                freq[i][1]++;
        }
        arr[n + 1] = 0;
        for (int j = 0; j < 2; j++)
        {
            freq[n + 1][j] = freq[n][j];
        }
        int totaltwo = 0, L = 0, R = n, i = 1, j = 1;
        while (j <= n+1)
        {
            if (arr[j] == 0)
            {
                for (int l = i; l < j; l++)
                {
                    int nowNeg = freq[j][1] - freq[l - 1][1];
                    int nowTwo = freq[j][0] - freq[l - 1][0];
                    if (nowNeg & 1)
                    {
                        if (arr[l] < 0)
                        {
                            nowTwo = freq[l - 1][0] - freq[i - 1][0];
                            if (nowTwo > totaltwo)
                            {
                                L = i - 1;
                                R = n - l + 1;
                                totaltwo = nowTwo;
                            }
                            nowTwo = freq[j][0] - freq[l][0];
                            if (nowTwo > totaltwo)
                            {
                                L = l;
                                R = n - j + 1;
                                totaltwo = nowTwo;
                            }
                        }
                    }
                    else
                    {
                        if (nowTwo > totaltwo)
                        {
                            L = l - 1;
                            if( j <= n ) {
                                R = n - j + 1;
                            } else {
                                R = 0;
                            }
                            totaltwo = nowTwo;
                        }
                    }
                }
                i = j + 1;
            }
            j++;
        }

        cout << L << " " << R << endl;
    }
}

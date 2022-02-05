#include <bits/stdc++.h>
using namespace std;
int f[105][25005];
int main()
{
    int c, n;
    cin >> c >> n;
    int arr[105];
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (j >= arr[i])
            {
                f[i][j] = max(f[i - 1][j], f[i - 1][j - arr[i]] + arr[i]);
            }
        }
    }

    /*
    khi xét qua 1 con bò thì có 2 trường hợp là lấy hoặc không lấy
    f[i][j] là max của i con bò có khối lượn tối đa là j
    f[i-1][j] là trường hợp k lấy bò
    f[i-1][j-arr[i]] là lấy bò*/
    cout << f[n][c];
}
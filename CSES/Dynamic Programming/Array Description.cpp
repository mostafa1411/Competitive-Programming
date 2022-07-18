#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define FAST_IO  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define show(x)  cout << ">> " << #x << " = " << x << '\n'
#define endl     '\n'
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const double EPS = 1e-10;  // epsilon
const double PI = acos(-1);
const int MOD = 1e9 + 7;
const int BASE = 31;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 5, M = 1e2 + 5;

int dx[] = {-1, 0, 1};
int n, m, a[N], dp[N][M];

int solve(int i, int last)
{
    if (i == n)
        return 1;
    if (~dp[i][last])
        return dp[i][last];
    if (a[i])
    {
        if (abs(a[i] - last) > 1)
            return 0;
        return dp[i][last] = solve(i + 1, a[i]) % MOD;
    }
    int ret = 0;
    if (!i)
    {
        for (int x = 1; x <= m; x++)
            ret = (ret + solve(i + 1, x)) % MOD;
    }
    else
    {
        for (int j = 0; j < 3; j++)
            if (last + dx[j] >= 1 && last + dx[j] <= m)
                ret = (ret + solve(i + 1, last + dx[j])) % MOD;
    }
    return dp[i][last] = ret;
}

void myMain()
{
    memset(dp, -1, sizeof dp);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << solve(0, a[0]) << endl;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    FAST_IO
    int t = 1;
//    cin >> t;
    while (t--)
        myMain();
    return 0;
}
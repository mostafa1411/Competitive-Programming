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
const int N = 1e6 + 5, M = 1e6 + 5;

int n, dp[N];

int solve(int x)
{
    if (x <= 0)
        return !x ? 0 : INF;
    if (~dp[x])
        return dp[x];
    int ret = INF, tmp = x;
    while (tmp)
    {
        int digit = tmp % 10;
        if (digit)
            ret = min(ret, 1 + solve(x - digit));
        tmp /= 10;
    }
    return dp[x] = ret;
}

void myMain()
{
    memset(dp, -1, sizeof dp);
    cin >> n;
    cout << solve(n) << endl;
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
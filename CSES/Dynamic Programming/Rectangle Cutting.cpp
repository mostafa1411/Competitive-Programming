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
const int N = 5e2 + 5, M = 1e2 + 5;

int dp[N][N];

int solve(int h, int w)
{
    if (h == w)
        return 1;
    if (~dp[h][w])
        return dp[h][w];
    int ret = INF;
    for (int i = 1; i < h; i++)
        ret = min(ret, solve(i, w) + solve(h - i, w));
    for (int i = 1; i < w; i++)
        ret = min(ret, solve(h, i) + solve(h, w - i));
    return dp[h][w] = ret;
}

void myMain()
{
    memset(dp, -1, sizeof dp);
    int a, b;
    cin >> a >> b;
    cout << solve(a, b) - 1 << endl;
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
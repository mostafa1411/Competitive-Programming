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
const int N = 1e3 + 5, M = 1e6 + 5;

int n, dp[N][N];
char grid[N][N];

int solve(int i, int j)
{
    if (i > n || j > n || grid[i][j] == '*')
        return 0;
    if (i == n && j == n)
        return 1;
    if (~dp[i][j])
        return dp[i][j];
    return dp[i][j] = (solve(i + 1, j) % MOD + solve(i, j + 1) % MOD) % MOD;
}

void myMain()
{
    memset(dp, -1, sizeof dp);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> grid[i][j];
    cout << solve(1, 1) << endl;
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
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
const int N = 5e3 + 5, M = 1e2 + 5;

int n, m, dp[N][N];
string a, b;

int solve(int i, int j)
{
    if (i == n)
        return m - j;
    if (j == m)
        return n - i;
    if (~dp[i][j])
        return dp[i][j];
    if (a[i] == b[j])
        return dp[i][j] = solve(i + 1, j + 1);
    return dp[i][j] = 1 + min({solve(i + 1, j + 1), solve(i, j + 1), solve(i + 1, j)});
}

void myMain()
{
    memset(dp, -1, sizeof dp);
    cin >> a >> b;
    n = a.length(), m = b.length();
    cout << solve(0, 0) << endl;
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
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
const int N = 5e3 + 5, M = 1e5 + 5;

int n;
ll a[N], dp[N][N][2];

ll solve(int i, int j, bool first)
{
    if (i == j)
        return a[i] * first;
    if (~dp[i][j][first])
        return dp[i][j][first];
    if (first)
        return dp[i][j][first] = max(a[i] + solve(i + 1, j, 0), a[j] + solve(i, j - 1, 0));
    return dp[i][j][first] = min(solve(i + 1, j, 1), solve(i, j - 1, 1));
}

void myMain()
{
    memset(dp, -1, sizeof dp);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << solve(0, n - 1, true) << endl;
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
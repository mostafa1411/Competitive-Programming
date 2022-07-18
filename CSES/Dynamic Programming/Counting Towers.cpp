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
const int N = 1e6 + 5, M = 1e2 + 5;

int n;
ll dp[N][2];

ll solve(int i, bool two)
{
    if (i == 1)
        return 1;
    if (~dp[i][two])
        return dp[i][two];
    if (two)
        return dp[i][two] = (solve(i - 1, false) % MOD + 4LL * solve(i - 1, true) % MOD) % MOD;
    return dp[i][two] = (2LL * solve(i - 1, false) % MOD + solve(i - 1, true) % MOD) % MOD;
}

void myMain()
{
    cin >> n;
    cout << (solve(n, false) + solve(n, true)) % MOD << endl;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    FAST_IO
    memset(dp, -1, sizeof dp);
    int t = 1;
    cin >> t;
    while (t--)
        myMain();
    return 0;
}
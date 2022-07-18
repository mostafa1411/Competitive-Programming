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

ll dp[N];

ll solve(int x)
{
    if (x <= 0)
        return !x;
    if (~dp[x])
        return dp[x];
    ll ret = 0;
    for (int i = 1; i <= 6; i++)
        (ret += solve(x - i)) %= MOD;
    return dp[x] = ret;
}

void myMain()
{
    int n;
    cin >> n;
    memset(dp, -1, sizeof dp);
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

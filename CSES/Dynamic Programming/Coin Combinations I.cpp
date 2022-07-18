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
const int N = 1e2 + 5, M = 1e6 + 5;

int n, x, a[N], dp[M];

int solve(int sum)
{
    if (sum >= x)
        return sum == x;
    if (~dp[sum])
        return dp[sum];
    int ret = 0;
    for (int i = 0; i < n; i++)
        (ret += solve(sum + a[i])) %= MOD;
    return dp[sum] = ret;
}

void myMain()
{
    memset(dp, -1, sizeof dp);
    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << solve(0) << endl;
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

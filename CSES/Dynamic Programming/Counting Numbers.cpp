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
const int MOD = 998244353;
const int BASE = 31;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5 + 5, M = 1e6 + 5;

string a, b;
ll dp[20][10][2][2][2];

ll solve(int i, int prev, bool equalA, bool equalB, bool trailingZeros)
{
    if (i == a.length())
        return 1;
    if (~dp[i][prev][equalA][equalB][trailingZeros])
        return dp[i][prev][equalA][equalB][trailingZeros];
    ll ret = 0;
    for (int d = (equalA ? a[i] - '0' : 0); d <= (equalB ? b[i] - '0' : 9); d++)
        if (trailingZeros || d != prev)
            ret += solve(i + 1, d, equalA && (a[i] - '0' == d), equalB && (b[i] - '0' == d), trailingZeros && !d);
    return dp[i][prev][equalA][equalB][trailingZeros] = ret;
}

void myMain()
{
    memset(dp, -1, sizeof dp);
    cin >> a >> b;
    while (a.length() < b.length())
        a = "0" + a;
    cout << solve(0, 0, true, true, true) << endl;
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

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
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e3 + 5, M = 1e6 + 5;

int n, m;
ll dp[N][(1 << 10) + 5];

void getNextStates(int mask, int nextMask, int i, vector<int>& nextStates)
{
    if (i == m)
        return void(nextStates.push_back(nextMask));
    if (mask & (1 << i))
        return void(getNextStates(mask, nextMask, i + 1, nextStates));
    getNextStates(mask, nextMask | (1 << i), i + 1, nextStates);
    if (i + 1 < m && !(mask & (1 << (i + 1))))
        getNextStates(mask, nextMask, i + 2, nextStates);
}

ll solve(int i, int mask)
{
    if (i == n)
        return !mask;
    if (~dp[i][mask])
        return dp[i][mask];
    ll ret = 0;
    vector<int> nextStates;
    getNextStates(mask, 0, 0, nextStates);
    for (auto& x : nextStates)
        (ret += solve(i + 1, x)) %= MOD;
    return dp[i][mask] = ret;
}

void myMain()
{
    memset(dp, -1, sizeof dp);
    cin >> m >> n;
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

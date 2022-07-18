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
const int N = 1e2 + 5, M = 1e5 + 5;

int n, a[N], dp[N][M];
set<int> ans;

int solve(int i, int sum)
{
    if (i == n)
    {
        if (sum)
            ans.emplace(sum);
        return 0;
    }
    if (~dp[i][sum])
        return dp[i][sum];
    return dp[i][sum] = solve(i + 1, sum) + solve(i + 1, sum + a[i]);
}

void myMain()
{
    memset(dp, -1, sizeof dp);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    solve(0, 0);
    cout << ans.size() << endl;
    for (auto& x : ans)
        cout << x << ' ';
    cout << endl;
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
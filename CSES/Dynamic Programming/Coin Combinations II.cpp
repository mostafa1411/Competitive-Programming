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

int n, x, a[N], dp[N][M];

void myMain()
{
    cin >> n >> x;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        for (int sum = 0; sum <= x; sum++)
        {
            dp[i][sum] += dp[i - 1][sum];
            if (sum >= a[i])
                (dp[i][sum] += dp[i][sum - a[i]]) %= MOD;
        }
    }
    cout << dp[n][x] << endl;
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
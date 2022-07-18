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
const int N = (1 << 20) + 5, M = 1e6 + 5;

int n, x, weight[25];
pair<int, int> dp[N];
// dp[i].first ==>  the minimum number of rides needed
// dp[i].second ==> the minimum group weight of people

void myMain()
{
    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    dp[0] = {1, 0};
    for (int mask = 1; mask < (1 << n); mask++)
    {
        dp[mask] = {n, 0};
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                auto option = dp[mask ^ (1 << i)];
                if (option.second + weight[i] <= x)
                    option.second += weight[i];
                else
                {
                    option.first++;
                    option.second = weight[i];
                }
                dp[mask] = min(dp[mask], option);
            }
        }
    }
    cout << dp[(1 << n) - 1].first << endl;
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
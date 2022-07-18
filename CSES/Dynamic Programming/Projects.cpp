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
const int N = 2e5 + 5, M = 1e6 + 5;

int n, statingDay[N], endingDay[N], reward[N], sz;
map<int, int> compress;

void myMain()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> statingDay[i] >> endingDay[i] >> reward[i];
        compress[statingDay[i]], compress[++endingDay[i]];
    }
    for (auto& it : compress)
        it.second = sz++;
    vector<vector<pair<int, int>>> projects(sz);
    for (int i = 0; i < n; i++)
        projects[compress[endingDay[i]]].emplace_back(compress[statingDay[i]], reward[i]);
    vector<ll> dp(sz);
    for (int i = 1; i < sz; i++)
    {
        dp[i] = dp[i - 1];
        for (auto& p : projects[i])
            dp[i] = max(dp[i], dp[p.first] + p.second);
    }
    cout << dp[sz - 1] << endl;
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
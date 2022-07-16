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
const int N = 2e5 + 5, M = 1e6 + 5;

void myMain()
{
    int n, k, ans = 1;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (auto& p : a)
        cin >> p.second >> p.first;
    sort(a.begin(), a.end());
    multiset<int> ms = {a[0].first};
    for (int i = 1; i < n; i++)
    {
        auto it = ms.upper_bound(a[i].second);
        if (it == ms.begin())
        {
            if (ms.size() == k)
                continue;
            ms.emplace(a[i].first);
        }
        else
        {
            ms.erase(--it);
            ms.emplace(a[i].first);
        }
        ans++;
    }
    cout << ans << endl;
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

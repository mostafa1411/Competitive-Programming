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
    int n, mn, mx, x;
    cin >> n >> mn >> mx;
    vector<ll> prefix(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        prefix[i] = prefix[i - 1] + x;
    }
    ll ans = -INF;
    multiset<ll> ms;
    for (int i = mn; i <= n; i++)
    {
        if (i > mx)
            ms.erase(ms.find(prefix[i - mx - 1]));
        ms.emplace(prefix[i - mn]);
        ans = max(ans, prefix[i] - *ms.begin());
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

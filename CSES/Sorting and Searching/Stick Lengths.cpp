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
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5 + 5, M = 1e6 + 5;

void myMain()
{
    int n;
    cin >> n;
    vector<ll> a(n), prefix(n + 1), suffix(n + 1);
    for (auto& item : a)
        cin >> item;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
        prefix[i + 1] = prefix[i] + a[i];
    suffix[n] = 0;
    for (int i = n - 1; i >= 0; i--)
        suffix[i] = suffix[i + 1] + a[i];
    ll ans = INF;
    for (int i = n - 1; i >= 0; i--)
        ans = min(ans, i * a[i] - prefix[i] + suffix[i + 1] - (n - 1 - i) * a[i]);
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

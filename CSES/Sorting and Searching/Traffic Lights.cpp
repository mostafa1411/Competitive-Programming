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
    int x, n, a;
    cin >> x >> n;
    set<int> cuts {0, x};
    multiset<int> lens {x};
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        auto r = cuts.upper_bound(a);
        auto l = r;
        l--;
        cuts.emplace(a);
        lens.erase(lens.find(*r - *l));
        lens.emplace(a - *l);
        lens.emplace(*r - a);
        cout << *lens.rbegin() << ' ';
    }
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

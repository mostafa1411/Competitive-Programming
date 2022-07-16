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
    int n, m, ans = 1;
    cin >> n >> m;
    vector<int> a(n), pos(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for (int i = 1; i < n; i++)
        ans += (pos[i] > pos[i + 1]);
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        set<int> st;
        if (a[x] != 1)
            st.emplace(a[x] - 1);
        if (a[x] != n)
            st.emplace(a[x]);
        if (a[y] != 1)
            st.emplace(a[y] - 1);
        if (a[y] != n)
            st.emplace(a[y]);
        for (auto& i : st)
            ans -= (pos[i] > pos[i + 1]);
        swap(a[x], a[y]);
        swap(pos[a[x]], pos[a[y]]);
        for (auto& i : st)
            ans += (pos[i] > pos[i + 1]);
        cout << ans << endl;
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

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
    int n, m, x;
    cin >> n >> m;
    multiset<int> ms;
    while (n--)
    {
        cin >> x;
        ms.emplace(x);
    }
    while (m--)
    {
        cin >> x;
        auto it = ms.upper_bound(x);
        if (ms.empty() || it-- == ms.begin())
        {
            cout << "-1\n";
            continue;
        }
        cout << *it << endl;
        ms.erase(it);
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

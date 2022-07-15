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
    int n;
    cin >> n;
    if (((n + (n & 1)) >> 1) & 1)
        return void(puts("NO"));
    vector<int> a, b;
    if (n & 1)
        b.emplace_back(n--);
    for (int i = 1; i * 2 <= n; i++)
    {
        (i & 1 ? a : b).emplace_back(i);
        (i & 1 ? a : b).emplace_back(n - i + 1);
    }
    cout << "YES\n" << a.size() << endl;
    for (auto& x : a)
        cout << x << ' ';
    cout << endl << b.size() << endl;
    for (auto& x : b)
        cout << x << ' ';
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

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
    queue<int> q;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
        q.emplace(i);
    while (q.size() > 1)
    {
        q.emplace(q.front());
        q.pop();
        ans.emplace_back(q.front());
        q.pop();
    }
    for (auto& x : ans)
        cout << x << ' ';
    if (!q.empty())
        cout << q.front();
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

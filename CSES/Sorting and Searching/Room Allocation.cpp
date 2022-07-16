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
    vector<tuple<int, int, int>> a(n);
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        cin >> get<0>(a[i]) >> get<1>(a[i]);
        get<2>(a[i]) = i;
    }
    sort(a.begin(), a.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(get<1>(a[0]), 1);
    ans[get<2>(a[0])] = 1;
    int cur = 2;
    for (int i = 1; i < n; i++)
    {
        auto top = pq.top(); pq.pop();
        if (get<0>(a[i]) > top.first)
            ans[get<2>(a[i])] = top.second;
        else
        {
            ans[get<2>(a[i])] = cur++;
            pq.emplace(top);
        }
        pq.emplace(get<1>(a[i]), ans[get<2>(a[i])]);
    }
    cout << cur - 1 << endl;
    for (auto& x : ans)
        cout << x << ' ';
    cout << endl;
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

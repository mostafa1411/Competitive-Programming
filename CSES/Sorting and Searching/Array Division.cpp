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

int n, k;
ll a[N];

bool good(ll x)
{
    int cnt = 1;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > x)
            return false;
        sum += a[i];
        if (sum > x)
        {
            cnt++;
            sum = a[i];
        }
    }
    return cnt <= k;
}

void myMain()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll l = 1, r = 1e18, mid;
    while (l < r)
    {
        mid = l + (r - l) / 2;
        good(mid) ? r = mid : l = mid + 1;
    }
    cout << l << endl;
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

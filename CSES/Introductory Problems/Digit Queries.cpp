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
const int MOD = 1e9 + 7;
const int BASE = 31;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 5, M = 1e6 + 5;

vector<ll> cnt(20);

void myMain()
{
    ll k;
    cin >> k;
    ll l = 0, r = 19, mid;
    while (r - l > 1)
    {
        mid = l + (r - l) / 2;
        (cnt[mid] < k ? l : r) = mid;
    }
    ll numLength = r;
    k -= cnt[numLength - 1];

    l = 0, r = 1e17;
    while (r - l > 1)
    {
        mid = l + (r - l) / 2;
        (mid * numLength < k ? l : r) = mid;
    }
    string num = to_string((ll)pow(10, numLength - 1) + r - 1);
    k -= numLength * (r - 1);
    cout << num[k - 1] << endl;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    FAST_IO
    for (ll i = 1, j = 10; i <= 18; i++, j *= 10)
        cnt[i] = cnt[i - 1] + (j - j / 10) * i;
    int t = 1;
    cin >> t;
    while (t--)
        myMain();
    return 0;
}

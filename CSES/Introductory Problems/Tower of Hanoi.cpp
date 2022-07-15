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

void solve(int cnt, int from, int to, int through)
{
    if (cnt == 0)
        return;
    solve(cnt - 1, from, through, to);
    cout << from << " " << to << endl;
    solve(cnt - 1, through, to, from);
}

void myMain()
{
    int n;
    cin >> n;
    cout << (1 << n) - 1 << endl;
    solve(n, 1, 3, 2);
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

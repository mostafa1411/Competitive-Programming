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

void myMain()
{
    int n;
    cin >> n;
    int len = (1 << n);
    for (int i = 0; i < len; i++)
    {
        string s;
        s.push_back((i & (1 << (n - 1)) ? '1' : '0'));
        for (int j = n - 1; j > 0; j--)
        {
            bool a = (i & (1 << j));
            bool b = (i & (1 << (j - 1)));
            s.push_back('0' + (a ^ b));
        }
        cout << s << endl;
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

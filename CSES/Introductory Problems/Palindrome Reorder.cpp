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

map<char, int> mp;

bool valid()
{
    int odd = 0;
    for (auto& it : mp)
        odd += (it.second & 1);
    return odd <= 1;
}

void myMain()
{
    string s;
    cin >> s;
    for (auto& c : s)
        mp[c]++;
    if (!valid())
        return void(puts("NO SOLUTION"));
    char ch = '.';
    string ans;
    for (auto& it : mp)
    {
        if (it.second & 1)
            ch = it.first;
        ans += string(it.second / 2, it.first);
    }
    int i = ans.length() - 1;
    if (ch != '.')
        ans.push_back(ch);
    while (i >= 0)
        ans.push_back(ans[i--]);
    cout << ans << endl;
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

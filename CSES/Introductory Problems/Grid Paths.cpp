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

// LEFT RIGHT UP DOWN
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
string s;
bool vis[7][7];

bool isValid(int x, int y)
{
    return min(x, y) >= 0 && max(x, y) < 7;
}

int dfs(int i, int x, int y)
{
    if (i == s.length())
        return x == 6 && y == 0;
    if (!isValid(x, y) || vis[x][y] || (x == 6 && y == 0))
        return 0;

    vector<bool> adjVis(4, true);
    for (int j = 0; j < 4; j++)
    {
        int newX = x + dx[j], newY = y + dy[j];
        if (isValid(newX, newY))
            adjVis[j] = vis[newX][newY];
    }

    if ((adjVis[0] && adjVis[1] && !adjVis[2] && !adjVis[3]) ||
        (!adjVis[0] && !adjVis[1] && adjVis[2] && adjVis[3]))
        return 0;

    if (isValid(x - 1, y - 1) && vis[x - 1][y - 1] && !adjVis[0] && !adjVis[2])
        return 0;
    if (isValid(x - 1, y + 1) && vis[x - 1][y + 1] && !adjVis[1] && !adjVis[2])
        return 0;
    if (isValid(x + 1, y - 1) && vis[x + 1][y - 1] && !adjVis[0] && !adjVis[3])
        return 0;
    if (isValid(x + 1, y + 1) && vis[x + 1][y + 1] && !adjVis[1] && !adjVis[3])
        return 0;

    vis[x][y] = true;
    int cnt = 0;
    if (s[i] == '?' || s[i] == 'R')
        cnt += dfs(i + 1, x, y + 1);
    if (s[i] == '?' || s[i] == 'L')
        cnt += dfs(i + 1, x, y - 1);
    if (s[i] == '?' || s[i] == 'U')
        cnt += dfs(i + 1, x - 1, y);
    if (s[i] == '?' || s[i] == 'D')
        cnt += dfs(i + 1, x + 1, y);
    vis[x][y] = false;
    return cnt;
}

void myMain()
{
    cin >> s;
    cout << dfs(0, 0, 0) << endl;
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

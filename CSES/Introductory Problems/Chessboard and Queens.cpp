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
    vector<string> board(8);
    vector<bool> diagonal(15);
    vector<int> col(8);
    int ans = 0;
    for (auto& row : board)
        cin >> row;
    iota(col.begin(), col.end(), 0);
    do {
        bool ok = true;
        for (int i = 0; i < 8; i++)
            ok &= board[i][col[i]] == '.';
        // checking right diagonal
        diagonal = vector<bool> (15, false);
        for (int i = 0; i < 8; i++)
        {
            if (diagonal[i + col[i]])
                ok = false;
            diagonal[i + col[i]] = true;
        }
        // checking left diagonal
        diagonal = vector<bool> (15, false);
        for (int i = 0; i < 8; i++)
        {
            if (diagonal[i + 7 - col[i]])
                ok = false;
            diagonal[i + 7 - col[i]] = true;
        }
        ans += ok;
    } while (next_permutation(col.begin(), col.end()));
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

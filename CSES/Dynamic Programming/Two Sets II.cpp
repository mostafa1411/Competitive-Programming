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
const int N = 5e2 + 5, M = N * N / 2;

int n, dp[N][M], sum;

int solve(int i, int currSum)
{
    if (currSum > sum)
        return 0;
    if (i == n)
        return currSum == sum;
    if (~dp[i][currSum])
        return dp[i][currSum];
    return dp[i][currSum] = (solve(i + 1, currSum + i) % MOD + solve(i + 1, currSum) % MOD) % MOD;
}

void myMain()
{
    memset(dp, -1, sizeof dp);
    cin >> n;
    sum = n * (n + 1) / 2;
    if (sum & 1)
        return void(cout << 0 << endl);
    sum >>= 1;
    cout << solve(1, 0) << endl;
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
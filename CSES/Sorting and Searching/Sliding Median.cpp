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

// policy-based data structures
#include <ext/pb_ds/assoc_container.hpp>  // Common file
#include <ext/pb_ds/tree_policy.hpp>      // Including tree_order_statistics_node_update
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
        tree<T,      // the type of the data that we want to insert (KEY)
        null_type, // the mapped policy
        less_equal<T>,  // the basis for comparison of two functions.
        rb_tree_tag,   // type of tree used (Red black)
        tree_order_statistics_node_update>; // contains various operations for updating the node variants of a tree-based container

void myMain()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    ordered_set<int> os;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i < k)
            os.insert(a[i]);
    }
    cout << *os.find_by_order((k - 1) / 2) << ' ';
    for (int i = k; i < n; i++)
    {
        os.erase(os.find_by_order(os.order_of_key(a[i - k])));
        os.insert(a[i]);
        cout << *os.find_by_order((k - 1) / 2) << ' ';
    }
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

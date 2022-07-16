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
        less<T>,  // the basis for comparison of two functions.
        rb_tree_tag,   // type of tree used (Red black)
        tree_order_statistics_node_update>; // contains various operations for updating the node variants of a tree-based container

bool cmp(tuple<int, int, int> a, tuple<int, int, int> b)
{
    if (get<0>(a) == get<0>(b))
        return get<1>(b) < get<1>(a);
    return get<0>(a) < get<0>(b);
}

bool cmp2(tuple<int, int, int> a, tuple<int, int, int> b)
{
    if (get<1>(a) == get<1>(b))
        return get<0>(a) > get<0>(b);
    return get<1>(a) < get<1>(b);
}

void myMain()
{
    int n;
    cin >> n;
    vector<tuple<int, int, int>> seg;
    vector<int> contains(n), contained(n);
    ordered_set<pair<int, int>> starts, ends;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        seg.emplace_back(l, r, i);
        starts.insert({l, i});
        ends.insert({r, i});
    }
    sort(seg.begin(), seg.end(), cmp);
    for (auto& t : seg)
    {
        auto it = --ends.lower_bound({get<1>(t) + 1, 0});
        contains[get<2>(t)] = ends.order_of_key(*it);
        ends.erase({get<1>(t), get<2>(t)});
    }
    sort(seg.begin(), seg.end(), cmp2);
    for (auto& t : seg)
    {
        auto it = --starts.lower_bound({get<0>(t) + 1, 0});
        contained[get<2>(t)] = starts.order_of_key(*it);
        starts.erase({get<0>(t), get<2>(t)});
    }
    for (auto x : contains)
        cout << x << ' ';
    cout << endl;
    for (auto x : contained)
        cout << x << ' ';
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

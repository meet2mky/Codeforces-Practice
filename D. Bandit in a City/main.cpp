#include <iostream>
#include <bitset>
#include <map>
#include <unordered_map>
#include <vector>
#include <cstring>
#include <set>
#include <utility>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cassert>
#include <chrono>
#include <cctype>
#include <iomanip>
#include <stack>
#include <ctime>
#include <iterator>
#include <sstream>
using namespace std;
#define sync                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define REPR(i, a, b) for (int i = (a); i > (b); i--)
#define ALL(x) (x).begin(), (x).end()
#define SETALL(x, val) fill(ALL(x), val)
#define SORT_UNIQUE(c) (sort(c.begin(), c.end()), c.resize(distance(c.begin(), unique(c.begin(), c.end()))))
#define SORT(a) (sort(ALL(a)))
#define SORTR(a) (SORT(a), reverse(ALL(a)))
#define SQUARE(x) ((x) * (x))
#define CUBE(x) ((x) * (x) * (x))
#define ODD(x) (x & 1)
#define EVEN(x) (!(x & 1))
#define MEMS0(x) memset((x), 0, sizeof(x))
#define MEMS1(x) memset((x), 1, sizeof(x))
#define MEMSM1(x) memset((x), -1, sizeof(x))
#define PB emplace_back
#define MP make_pair
#define F first
#define S second
#define VB vector<bool>
#define VVB vector<VB>
#define VI vector<int>
#define VVI vector<VI>
#define PII pair<int, int>
#define VPII vector<PII>
#define SP(x) setprecision(x)
#define endl '\n'
#define LL long long
#define LD long double
#define SZ(z) (int)(z).size()
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define EPS 0.0000001 // eps = 1e-7
#define PI 3.141592653589793238
const LL MOD = 1000000007;
#ifndef ONLINE_JUDGE
#define DEBUG(...)      \
    cout << "[DEBUG] "; \
    W(__VA_ARGS__);
#else
#define DEBUG(...)
#endif
template <class T>
void _R(T &x)
{
    cin >> x;
}
void _R(int &x) { cin >> x; }
void _R(int64_t &x) { cin >> x; }
void _R(double &x) { cin >> x; }
void _R(long double &x) { cin >> x; }
void _R(char &x) { cin >> x; }
void _R(char *x) { cin >> x; }
void _R(string &x) { cin >> x; }
void R() {}
template <class T, class... U>
void R(T &head, U &... tail)
{
    _R(head);
    R(tail...);
}
template <class T>
void _W(const T &x) { cout << x; }
void _W(const int &x) { cout << x; }
void _W(const int64_t &x) { cout << x; }
void _W(const double &x) { cout << fixed << SP(8) << x; }
void _W(const long double &x) { cout << fixed << SP(16) << x; }
void _W(const char &x) { cout << x; }
void _W(const char *x) { cout << x; }
void _W(const string &x) { cout << x; }
template <class T, class U>
void _W(const pair<T, U> &x)
{
    _W(x.F);
    cout << ' ';
    _W(x.S);
}
template <class T>
void _W(const vector<T> &x)
{
    for (auto i = x.begin(); i != x.end(); _W(*i++))
        if (i != x.cbegin())
            cout << ' ';
}
void W() {}
template <class T, class... U>
void W(const T &head, const U &... tail)
{
    _W(head);
    cout << (sizeof...(tail) ? ' ' : '\n');
    W(tail...);
}
#define int long long
const int N = 2e5 + 10;
struct Node
{
    int fr, mx, sz;
    Node()
    {
        fr = 0;
        mx = 0;
        sz = 0;
    }
    Node(int val)
    {
        fr = 0;
        mx = val;
        sz = 1;
    }
};
Node combine(Node &a, Node &b)
{
    Node t;
    t.sz = a.sz + b.sz;
    t.mx = max(a.mx, b.mx);
    t.fr = t.mx * (t.sz) - (a.sz * a.mx - a.fr + b.sz * b.mx - b.fr);
    return t;
}
Node adds(Node &a, int val)
{
    int can = min(val, a.fr);
    a.fr -= can;
    val -= can;
    if (val)
    {
        a.mx += val / (a.sz) + (val % a.sz != 0);
        a.fr = (a.sz - val % a.sz) * (val % a.sz != 0);
    }
    return a;
}
int n;
VI g[N];
VI value(N, 0);
VI color(N);
vector<Node> dp(N);
void dfs(int s, int p = -1)
{

    int childs = 0;
    for (auto nx : g[s])
    {
        if (nx == p)
            continue;
        if (color[nx] == 0)
        {
            dfs(nx, s);
            childs++;
        }
    }
    if (childs == 0)
    {
        dp[s] = Node(value[s]);
    }
    else
    {
        for (auto nx : g[s])
        {
            if (nx == p)
            {
                continue;
            }
            dp[s] = combine(dp[s], dp[nx]);
        }
        dp[s] = adds(dp[s], value[s]);
    }
    color[s] = 2;
}
void solve()
{
    R(n);
    for (int i = 1; i < n; i++)
    {
        int a;
        R(a);
        g[a].push_back(i + 1);
        g[i + 1].push_back(a);
    }
    REP(i, 1, n + 1)
    {
        R(value[i]);
    }

    dfs(1);
    W(dp[1].mx);
}

signed main()
{
    sync;
#ifndef ONLINE_JUDGE
    auto begin = std::chrono::high_resolution_clock::now();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    //cin >> t;
    for (int testcase = 1; testcase <= t; testcase++)
    {
        //cout << "Case #" << testcase << ": ";
        solve();
    }

#ifndef ONLINE_JUDGE
    auto end = std::chrono::high_resolution_clock::now();
    cerr << setprecision(4) << fixed;
    cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
#endif
    return 0;
}
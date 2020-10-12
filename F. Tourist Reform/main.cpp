/*****************************************************************
IN GOD WE TRUST !!   

Author:- meet2mky
Date: -
Problem:-
Institue:- NITA
******************************************************************/
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
const int MOD = 1000000007;
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
#ifndef ONLINE_JUDGE
#define DEBUG(...)      \
    cout << "[DEBUG] "; \
    W(__VA_ARGS__);
#else
#define DEBUG(...)
#endif

//#define NEEDLONG
#ifdef NEEDLONG
#define int long long
#endif
/*****************************************************************
Read the problem carefully!!
Take inputs carefully
Care for array index out of bound errors
Check for overflow
Divide the problem in several parts if possible
Keep Calm and believe on yourself.
Do not panic & work hard you will get it right one day


LOOP ITERATORS MIXING ~ WASTE OF TIME AND LOTS OF BUG
******************************************************************/
vector<VPII> g;
VPII ed;
VB ori;
VB bridge;
int timer = 0;
VI tin, low;
VB vis;
void dfs0(int s, int p = -1)
{
    vis[s] = true;
    tin[s] = low[s] = ++timer;
    for (auto nx : g[s])
    {
        int to = nx.first;
        if (to == p)
            continue;
        if (!vis[to])
        {
            dfs0(to, s);
            low[s] = min(low[s], low[to]);
            if (low[to] > tin[s])
            {
                bridge[nx.second] = true;
            }
        }
        else
        {
            low[s] = min(low[s], tin[to]);
        }
    }
}
void mark_bridges(int n)
{
    tin.resize(n + 1);
    low.resize(n + 1);
    vis.resize(n + 1);
    SETALL(vis, false);
    dfs0(1);
}
int dfs1(int s, int p = -1)
{
    vis[s] = true;
    int curr = 1;
    for (auto nx : g[s])
    {
        int edi = nx.second;
        int to = nx.first;
        if (bridge[edi] || to == p || vis[to])
        {
            continue;
        }
        curr += dfs1(to, s);
    }
    return curr;
}
int dfs2(int s, int p = -1)
{
    vis[s] = true;
    for (auto nx : g[s])
    {
        int edi = nx.second;
        int to = nx.first;
        if (to == p)
            continue;
        if (!vis[to])
        {
            ed[edi] = {s, to};
            dfs2(to, s);
            ori[edi] = true;
        }
        else
        {
            if (!ori[edi])
            {
                ed[edi] = {s, to};
                ori[edi] = true;
            }
        }
    }
}
void solve()
{
    int n, m;
    R(n, m);
    g.resize(n + 1);
    ed.resize(m + 1);
    ori.resize(m + 1);
    bridge.resize(m + 1);
    SETALL(bridge, false);
    SETALL(ori, false);
    REP(i, 1, m + 1)
    {
        int u, v;
        cin >> u >> v;
        ed[i] = {u, v};
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }
    mark_bridges(n);
    // we can not travel bridges
    SETALL(vis, false);
    int ans = -1;
    int root = -1;
    REP(i, 1, n + 1)
    {
        if (!vis[i])
        {
            int curr = dfs1(i);
            if (curr > ans)
            {
                ans = curr;
                root = i;
            }
        }
    }
    SETALL(vis, false);
    dfs2(root);
    W(ans);
    REP(i, 1, m + 1)
    {
        if (bridge[i])
        {
            swap(ed[i].first, ed[i].second);
        }
    }
    REP(i, 1, m + 1)
    {
        W(ed[i]);
    }
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
        //cout << "Case " << testcase << ": ";
        solve();
    }

#ifndef ONLINE_JUDGE
    auto end = std::chrono::high_resolution_clock::now();
    cout << setprecision(4) << fixed;
    cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
#endif
    return 0;
}
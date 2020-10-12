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
#define PB push_back
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

#define NEEDLONG
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

struct T
{
    int x, y, idx;
};
int cost(const T &a, const T &b, bool flag)
{
    if (flag)
        return min(abs(a.x - b.x), abs(a.y - b.y));
    return abs(a.x - b.x) + abs(a.y - b.y);
}
bool compx(const T &a, const T &b)
{
    return a.x < b.x;
}
bool compy(const T &a, const T &b)
{
    return a.y < b.y;
}
int dijkstra(VPII g[], int m, T src, T dest)
{
    VI dist(m + 2, LINF);
    VB vis(m + 2, false);
    VI p(m + 2, -1);
    dist[src.idx] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, src.idx});
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if (vis[u])
            continue;
        vis[u] = true;
        for (auto nx : g[u])
        {
            int v = nx.first;
            int ew = nx.second;
            if (dist[v] > dist[u] + ew)
            {
                dist[v] = dist[u] + ew;
                pq.push({-dist[v], v});
            }
        }
    }
    return dist[dest.idx];
}
void solve()
{
    int n, m;
    R(n, m);
    int sx, sy, fx, fy;
    R(sx, sy, fx, fy);
    vector<T> pts(m);
    REP(i, 0, m)
    {
        R(pts[i].x, pts[i].y);
        pts[i].idx = i;
    }
    VPII g[m + 2];
    sort(ALL(pts), compx);
    REP(i, 0, m - 1)
    {
        int u = pts[i].idx;
        int v = pts[i + 1].idx;
        int dist = cost(pts[i], pts[i + 1], 1);
        g[u].push_back({v, dist});
        g[v].push_back({u, dist});
    }
    sort(ALL(pts), compy);
    REP(i, 0, m - 1)
    {
        int u = pts[i].idx;
        int v = pts[i + 1].idx;
        int dist = cost(pts[i], pts[i + 1], 1);
        g[u].push_back({v, dist});
        g[v].push_back({u, dist});
    }
    T src, dest;
    src.x = sx, src.y = sy, src.idx = m;
    dest.x = fx, dest.y = fy, dest.idx = m + 1;
    REP(i, 0, m)
    {
        int u = pts[i].idx;
        int v = src.idx;
        int dist = cost(pts[i], src, 1);
        g[u].push_back({v, dist});
        g[v].push_back({u, dist});
    }
    REP(i, 0, m)
    {
        int u = pts[i].idx;
        int v = dest.idx;
        int dist = cost(pts[i], dest, 0);
        g[u].push_back({v, dist});
        g[v].push_back({u, dist});
    }
    int u = src.idx;
    int v = dest.idx;
    int dist = cost(src, dest, 0);
    g[u].push_back({v, dist});
    g[v].push_back({u, dist});
    int ans = dijkstra(g, m, src, dest);
    W(ans);
}
signed main()
{
    sync;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
    for (int testcase = 1; testcase <= t; testcase++)
    {
        solve();
    }
    return 0;
}
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

#ifndef ONLINE_JUDGE
#define cout cerr
#endif

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

int n, m, a, b, c;
vector<VPII> g;
vector<pair<int, PII>> edges;
VVI id;
VI inspt, p, euler, height, fo, best_cyc, cost, marked, intree, notintree;
int best_ans;
VI tree(210);
int N; // tree size
void input()
{
    p.resize(n);
    g.resize(n);
    cost.resize(n);
    fo.resize(n);
    height.resize(n);
    marked.resize(n);
    id.resize(n);
    REP(i, 0, n)
    {
        id[i].resize(n);
        SETALL(id[i], -1);
    }
    edges.clear();
    REP(i, 0, m)
    {
        R(a, b, c);
        a--;
        b--;
        if (id[a][b] != -1)
        {
            edges[id[a][b]] = {min(edges[id[a][b]].F, c), {a, b}};
        }
        else
        {
            id[a][b] = SZ(edges);
            id[b][a] = SZ(edges);
            edges.push_back({c, {a, b}});
        }
    }
    m = SZ(edges);
    notintree.resize(m);
    SETALL(notintree, 1);
    REP(i, 0, m)
    {
        a = edges[i].S.F;
        b = edges[i].S.S;
        c = edges[i].F;
        g[a].PB({b, c});
        g[b].PB({a, c});
    }
}

void dijkstra(int src)
{
    REP(i, 0, n)
    {
        cost[i] = INF;
        marked[i] = 0;
        p[i] = -1;
    }
    cost[src] = 0;
    priority_queue<PII, VPII, greater<PII>> pq;
    pq.push({cost[src], src});
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if (marked[u])
            continue;
        marked[u] = 1;
        for (PII pt : g[u])
        {
            if (cost[pt.first] > pt.second + cost[u])
            {

                cost[pt.first] = cost[u] + pt.second;
                p[pt.first] = u;
                pq.push({cost[pt.first], pt.first});
            }
        }
    }
}

void dfs(int src)
{
    fo[src] = euler.size();
    euler.push_back(src);
    for (auto to : g[src])
    {
        if (p[to.first] == src)
        {
            intree.push_back(id[src][to.first]);
            height[to.first] = height[src] + 1;
            dfs(to.first);
            euler.push_back(src);
        }
    }
}
int query(int l, int r) // [l..r)
{
    if (l >= r)
        assert(false && "QUERY NOT OK!");
    int h = INF;
    int u = -1;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
        {
            if (height[tree[l]] < h)
            {
                h = height[tree[l]];
                u = tree[l];
            }
            l++;
        }
        if (r & 1)
        {
            --r;
            if (height[tree[r]] < h)
            {
                h = height[tree[r]];
                u = tree[r];
            }
        }
    }
    return u;
}
void solve()
{
    while (true)
    {
        best_ans = INF;
        best_cyc.clear();
        R(n);
        if (n == -1)
            break;
        R(m);
        input();
        REP(src, 0, n)
        {
            dijkstra(src);
            // DEBUG("d");
            intree.clear();
            euler.clear();
            REP(i, 0, n)
            {
                fo[i] = -1;
                height[i] = INF;
            }
            height[src] = 0;

            dfs(src);
            N = SZ(euler);
            // build
            REP(i, 0, N)
            {
                tree[i + N] = euler[i];
            }
            REPR(i, n - 1, 0)
            {
                tree[i] = (height[tree[i << 1]] < height[tree[i << 1 | 1]]) ? tree[i << 1] : tree[i << 1 | 1];
            }
            for (auto node : intree)
            {
                notintree[node] = 0;
            }
            REP(i, 0, m)
            {
                if (notintree[i])
                {
                    int x = edges[i].S.F;
                    int y = edges[i].S.S;
                    int c = edges[i].F;
                    int fox = fo[x];
                    int foy = fo[y];
                    if (fox == -1 || foy == -1)
                        continue;
                    if (fox > foy)
                    {
                        swap(fox, foy);
                    }
                    foy++;
                    int u = query(fox, foy);
                    int cyc_cost = cost[x] + cost[y] - 2 * cost[u] + c;
                    if (u != x && u != y && cyc_cost < best_ans)
                    {
                        best_ans = cyc_cost;
                        best_cyc.clear();
                        for (int now = x; now != u; now = p[now])
                        {
                            best_cyc.push_back(now);
                        }
                        best_cyc.push_back(u);
                        reverse(ALL(best_cyc));
                        for (int now = y; now != u; now = p[now])
                        {
                            best_cyc.push_back(now);
                        }
                    }
                }
            }
            for (auto node : intree)
            {
                notintree[node] = 1;
            }
        }
        if (best_ans == INF)
        {
            W("No Solution");
        }
        else
        {
            for (auto &x : best_cyc)
                x++;
            W(best_cyc);
        }
    }
}
signed main()
{
    sync;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    //  cin >> t;
    for (int testcase = 1; testcase <= t; testcase++)
    {
        solve();
    }
    return 0;
}
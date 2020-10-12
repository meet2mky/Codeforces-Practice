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
struct HASH
{
    size_t operator()(const pair<int, int> &x) const
    {
        return hash<long long>()(((long long)x.first) ^ (((long long)x.second) << 32));
    }
};
void solve()
{
    int n, m, k;
    int N = 0;
    R(n, m, k);
    VI rows[n + 1];
    VI cols[m + 1];
    unordered_map<pair<int, int>, int, HASH> mp;
    // row 1.....n
    // col n + 1 ..... n + m
    // points n + m + 1..... n + m + k..... n + m + k + 1 // if n,m not in k
    int id = n + m + 1;
    VPII pts(k);
    REP(i, 0, k)
    {
        int row, col;
        R(row, col);
        pts[i] = {row, col};
        mp[{row, col}] = id++;
        rows[row].push_back(col);
        cols[col].push_back(row);
    }
    if (mp.find({n, m}) == mp.end())
    {
        mp[{n, m}] = id++;
    }
    int sn = mp[{1, 1}];
    int fn = mp[{n, m}];
    VPII g[id];
    // we don't care if (n,m) is lit or not if
    // we just connect this point to row node and col node with 1 cost
    g[fn].push_back({n, 1});
    g[n].push_back({fn, 1});
    g[fn].push_back({n + m, 1});
    g[n + m].push_back({fn, 1});
    for (auto pt : pts)
    {
        int row = pt.first;
        int col = pt.second;
        int node1 = mp[{row, col}];
        REP(i, -1, 2)
        {
            int r = row + i;
            if (r >= 1 && r <= n)
            {
                g[node1].push_back({r, 1});
                g[r].push_back({node1, 1});
            }
        }
        REP(i, -1, 2)
        {
            int c = col + i;
            if (c >= 1 && c <= m)
            {
                c += n;
                g[node1].push_back({c, 1});
                g[c].push_back({node1, 1});
            }
        }
    }
    REP(row, 1, n + 1)
    {
        SORT(rows[row]);
        REP(i, 1, SZ(rows[row]))
        {
            int colr = rows[row][i];
            int coll = rows[row][i - 1];
            if (coll + 1 == colr)
            {
                int a = mp[{row, coll}];
                int b = mp[{row, colr}];
                g[a].push_back({b, 0});
                g[b].push_back({a, 0});
            }
        }
    }
    REP(col, 1, m + 1)
    {
        SORT(cols[col]);
        REP(i, 1, SZ(cols[col]))
        {
            if (cols[col][i] == cols[col][i - 1] + 1)
            {
                int a = mp[{cols[col][i], col}];
                int b = mp[{cols[col][i - 1], col}];
                g[a].push_back({b, 0});
                g[b].push_back({a, 0});
            }
        }
    }
    deque<pair<int, int>> q;
    VB vis(id, false);
    q.push_back({sn, 0});
    vis[sn] = true;
    int ans = -2;
    while (!q.empty())
    {
        int u = q.front().first;
        int w = q.front().second;
        q.pop_front();
        if (u == fn)
        {
            ans = w;
            break;
        }
        for (auto to : g[u])
        {
            if (!vis[to.first])
            {
                vis[to.first] = true;
                if (to.second == 0)
                {
                    q.push_front({to.first, w});
                }
                else
                {
                    q.push_back({to.first, w + to.second});
                }
            }
        }
    }
    W(ans / 2);
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
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
const int N = 1e5 + 10;
struct Type
{
    int to;
    int cost;
    int type;
    int en;
    Type(int to_ = -1, int cost_ = INF, int type_ = 3, int en_ = -1) : to(to_), cost(cost_), type(type_), en(en_)
    {
    }
};
vector<Type> g[N];
int n, m, k;
VB used;
struct cmp
{
    bool operator()(const pair<PII, PII> &a, const pair<PII, PII> &b)
    {
        if (a.F.F != b.F.F)
        {
            return a.F.F > b.F.F;
        }
        return a.F.S > b.F.S;
    }
};
void dik(int s)
{
    VI d(n + 1, LINF);
    VB marked(n + 1, false);
    priority_queue<pair<PII, PII>, vector<pair<PII, PII>>, cmp> pq;
    marked[1] = true;
    d[1] = 0;
    for (auto nx : g[1])
    {
        d[nx.to] = nx.cost;
        pq.push({{nx.cost, nx.type}, {nx.to, nx.en}});
    }
    while (!pq.empty())
    {
        int to = pq.top().S.F;
        int en = pq.top().S.S;
        int wto = pq.top().S.S;
        pq.pop();
        if (marked[to])
            continue;
        marked[to] = true;
        used[en] = true;
        for (auto nx : g[to])
        {
            if (d[nx.to] > wto + nx.cost)
            {
                d[nx.to] = wto + nx.cost;
                pq.push({{d[nx.cost], nx.cost}, {nx.to, nx.en}});
            }
        }
    }
}

void solve()
{
    R(n, m, k);
    used.resize(m + k);
    SETALL(used, false);
    REP(i, 0, m)
    {
        int u, v, d;
        g[u].PB(Type(v, d, 1, 0));
        g[v].PB(Type(u, d, 1, 0));
    }
    REP(i, 0, k)
    {
        int s, d;
        R(s, d);
        g[1].PB(Type(s, d, 0, m + i));
        g[s].PB(Type(1, d, 0, m + i));
    }
    dik(1);
    int res = 0;
    REP(i, 0, k)
    {
        if (!used[m + i])
        {
            res++;
        }
    }
    W(res);
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
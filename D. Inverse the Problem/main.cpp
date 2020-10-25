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
class DSU
{
    vector<int> par1d;
    vector<int> sz1d;
    vector<vector<pair<int, int>>> par2d;
    vector<vector<int>> sz2d;
    int D1, D2;

public:
    DSU(int n)
    {
        par1d = vector<int>(n);
        sz1d = vector<int>(n);
        REP(i, 0, n)
        {
            sz1d[i] = 1;
            par1d[i] = i;
        }
        D1 = 1, D2 = 0;
    }
    DSU(int n, int m)
    {
        par2d = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(m));
        sz2d = vector<vector<int>>(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                par2d[i][j] = MP(i, j);
                sz2d[i][j] = 1;
            }
        }
        D1 = 0, D2 = 1;
    }
    pair<int, int> findparent(pair<int, int> a)
    {
        if (par2d[a.first][a.second] == a)
            return a;
        return par2d[a.first][a.second] = findparent(par2d[a.first][a.second]);
    }
    int findparent(int a)
    {
        if (par1d[a] == a)
            return a;
        return par1d[a] = findparent(par1d[a]);
    }
    bool unite(pair<int, int> a, pair<int, int> b)
    {
        a = findparent(a);
        b = findparent(b);
        if (a == b)
        {
            return false; // unsucess
        }
        if (sz2d[a.first][a.second] < sz2d[b.first][b.second])
        {
            swap(a, b);
        }
        par2d[b.first][b.second] = a;
        sz2d[a.first][a.second] += sz2d[b.first][b.second];
        return true; // sucess;
    }
    bool unite(int a, int b)
    {
        a = findparent(a);
        b = findparent(b);
        if (a == b)
        {
            return false;
        }
        if (sz1d[a] < sz1d[b])
        {
            swap(a, b);
        }
        par1d[b] = a;
        sz1d[a] += sz1d[b];
        return true;
    }
    bool isroot(pair<int, int> a)
    {
        return findparent(a) == a;
    }
    bool isroot(int a)
    {
        return findparent(a) == a;
    }
    int size(pair<int, int> a)
    {
        a = findparent(a);
        return sz2d[a.first][a.second];
    }
    int size(int a)
    {
        a = findparent(a);
        return sz1d[a];
    }
};
class LCA
{
public:
    int n_;   // graph size
    int root; // root
    int n;    // segment size
    vector<vector<int>> g;
    int oo = 0x3f3f3f3f;
    vector<int> euler;
    vector<int> first;
    vector<int> height;
    vector<int> t;
    vector<bool> vis;
    bool done;

public:
    LCA(int n_)
    {
        this->n_ = n_;
        g.resize(n_);
        height.resize(n_);
        first.resize(n_);
        vis.resize(n_);
        done = false;
    }
    void run(int root)
    {
        this->root = root;
        fill(vis.begin(), vis.end(), false);
        fill(first.begin(), first.end(), -1);
        dfs(this->root);
        segment();
        this->done = true;
    }
    void addedge(int a, int b)
    {
        g[a].push_back(b);
        g[b].push_back(a);
    }
    void dfs(int s, int p = -1)
    {
        if (p == -1)
            height[s] = 0;
        else
            height[s] = height[p] + 1;
        first[s] = euler.size();
        euler.push_back(s);
        vis[s] = true;
        for (auto nx : this->g[s])
        {
            if (nx == p)
                continue;
            if (!this->vis[nx])
            {
                dfs(nx, s);
                this->euler.push_back(s);
            }
        }
    }
    void segment()
    {
        n = euler.size();
        t.resize(2 * n);
        for (int i = 0; i < n; i++)
        {
            t[i + n] = euler[i];
        }
        for (int i = n - 1; i > 0; i--)
        {
            if (height[t[i << 1]] > height[t[i << 1 | 1]])
            {
                t[i] = t[i << 1 | 1];
            }
            else
            {
                t[i] = t[i << 1];
            }
        }
    }
    int lca(int a, int b)
    {

        assert(done == true);
        assert(a < n && a >= 0 && b >= 0 && b < n); // valid query
        int l = first[a];
        int r = first[b];
        if (l > r)
        {
            swap(l, r);
        }
        return query(l, r + 1);
    }
    int query(int l, int r)
    {
        int res = t[l + n];
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
            {
                if (height[t[l]] < height[res])
                {
                    res = t[l];
                }
                l++;
            }
            if (r & 1)
            {
                --r;
                if (height[t[r]] < height[res])
                {
                    res = t[r];
                }
            }
        }
        return res; // node returned
    }
};
void solve()
{
    int n;
    R(n);
    VVI d(n, VI(n, 0));
    REP(i, 0, n)
    {
        REP(j, 0, n)
        {
            R(d[i][j]);
        }
    }
    bool looksgood = true;
    vector<pair<int, PII>> edges;
    REP(i, 0, n)
    {
        REP(j, i, n)
        {
            if (i == j)
            {
                looksgood &= (d[i][j] == 0);
            }
            else
            {
                looksgood &= (d[i][j] != 0) & (d[i][j] == d[j][i]);
                edges.push_back(MP(d[i][j], MP(i, j)));
            }
        }
    }
    if (!looksgood)
    {

        W("NO");
        return;
    }
    SORT(edges);
    DSU dsu(n);
    LCA lcatree(n);
    for (auto x : edges)
    {
        int a = x.second.first;
        int b = x.second.second;
      //  int cos = x.first;
        if (dsu.unite(a, b))
        {
            lcatree.addedge(a, b);
        }
    }
    lcatree.run(0);
    bool ok = true;
    REP(i, 0, n)
    {
        REP(j, i + 1, n)
        {
            int lca = lcatree.lca(i, j);
            ok &= (d[i][j] == (d[i][0] + d[j][0] - 2 * d[lca][0]));
        }
    }
    if (!ok)
    {
        W("NO");
        return;
    }
    W("YES");
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
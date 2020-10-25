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
template <class T = int64_t>
class Dijkstra
{
public:
    int n, source;                  // number of nodes,source
    bool done;                      // dijkstra [done] by source
    vector<vector<pair<int, T>>> g; // graph directed
    vector<bool> vis;               // if reachable x upon calling run(x)
    vector<int> par;                // parent array for run(x)
    vector<T> dist;                 // dist array for run(x)

    //----------------------------------------------------------------//
    T oo = 0x3f3f3f3f3f3f3f3f; // SET THIS PLEASE FIRST
    //----------------------------------------------------------------//
    /* 
        ZERO based indexing /// BE CAREFUL.....
        assumes NO negative weight cycle......
    */
    Dijkstra(int n_)
    {
        this->n = n_;
        g.resize(this->n);
        vis.resize(this->n);
        par.resize(this->n);
        dist.resize(this->n);
        source = -1;
        done = false;
    }
    void addedge(int a, int b, T cost, bool bidir = false)
    {
        this->g[a].push_back(make_pair(b, cost));
        if (bidir)
        {
            this->g[b].push_back(make_pair(a, cost));
        }
    }
    void run(int s)
    {
        for (int i = 0; i < this->n; i++)
        {
            this->dist[i] = oo;
            this->vis[i] = false;
            this->par[i] = false;
        }
        this->dist[s] = 0; // refrence distance
        this->par[s] = -1;
        auto comp = [](const pair<int, T> &a, const pair<int, T> &b) {
            return a.second > b.second;
        };
        priority_queue<pair<int, T>, vector<pair<int, T>>, decltype(comp)> pq(comp);
        pq.push(make_pair(s, this->dist[s]));

        while (!pq.empty())
        {
            int u = pq.top().first;
            T dis = pq.top().second;
            pq.pop();
            if (this->vis[u])
            {
                continue;
            }
            this->vis[u] = true;
            for (PII nx : g[u])
            {
                if (this->dist[nx.first] > dis + nx.second) // relax
                {
                    this->dist[nx.first] = dis + nx.second;
                    this->par[nx.first] = u;
                    pq.push(make_pair(nx.first, this->dist[nx.first]));
                }
            }
            this->source = s;
            this->done = true;
        }
    }
    vector<T> getdistarray()
    {
        assert(done == true && "RUN FIRST");
        return this->dist;
    }
    vector<bool> getvisarray()
    {
        assert(done == true && "RUN FIRST");
        return this->vis;
    }
    vector<int> getpararray()
    {
        assert(done == true && "RUN FIRST");
        return this->par;
    }
    T getdist(int to)
    {
        assert(done == true && "RUN FIRST");
        return this->dist[to];
    }
    bool reachable(int to)
    {
        assert(done == true && "RUN FIRST");
        return this->vis[to];
    }
    vector<int> getpath(int to)
    {
        if (!reachable(to))
        {
            return vector<int>();
        }

        vector<int> path;
        for (int u = to; u != this->source; u = this->par[u])
        {
            path.push_back(u);
        }
        path.push_back(this->source);
        reverse(path.begin(), path.end());
        return path;
    }
};
void solve()
{
    int n, m, k;
    R(n, m, k);
    Dijkstra<long long> D(n);
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        R(a, b, c);
        D.addedge(a - 1, b - 1, c, true);
        edges.push_back({a - 1, b - 1});
    }
    vector<long long> dist[n];
    for (int i = 0; i < n; i++)
    {
        D.run(i);
        dist[i] = D.getdistarray();
    }
    vector<pair<int, int>> routes;
    for (int i = 0; i < k; i++)
    {
        int a, b;
        R(a, b);
        routes.push_back({a - 1, b - 1});
    }
    int cost = LINF;
    for (auto x : edges)
    {
        int costnow = 0;
        for (auto y : routes)
        {
            int a = y.first;
            int b = y.second;
            long long w1 = dist[a][x.first] + dist[b][x.second];
            long long w2 = dist[a][x.second] + dist[b][x.first];
            costnow += min(w1, min(dist[a][b], w2));
        }
        cost = min(cost, costnow);
    }
    W(cost);
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
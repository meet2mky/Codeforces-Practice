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
LD fun1(LD midtime, VI &a, int n)
{
    LD dist = 0;
    LD speed = 1.0;
    REP(i, 1, n + 1)
    {
        LD disnow = (LD)(a[i] - a[i - 1]);
        if (midtime >= disnow / speed)
        {
            midtime -= disnow / speed;
            dist += disnow;
        }
        else
        {
            dist += speed * midtime;
            return dist;
        }
        speed += 1.0;
    }
    if (midtime > 0)
    {
        dist += speed * midtime;
    }
    return dist;
}
LD fun2(LD midtime, VI &a, int n)
{

    LD dist = 0;
    LD speed = 1.0;
    REPR(i, n, -1)
    {

        LD disnow = (LD)(a[i + 1] - a[i]);

        if (midtime >= disnow / speed)
        {
            midtime -= disnow / speed;
            dist += disnow;
        }
        else
        {

            dist += speed * midtime;
            return dist;
        }

        speed += 1.0;
    }
    if (midtime > 0)
    {
        dist += speed * midtime;
    }
    return dist;
}
void solve()
{
    int n, l;
    R(n, l);
    VI a(n + 2);
    a[0] = 0;
    REP(i, 1, n + 1)
    {
        R(a[i]);
    }
    a[n + 1] = l;
    LD mintime = 0;
    LD maxtime = l;
    while (maxtime - mintime > EPS)
    {
        LD midtime = (maxtime + mintime) / 2.0;
        LD distcar1 = fun1(midtime, a, n);
        LD distcar2 = fun2(midtime, a, n);
        if (distcar1 + distcar2 >= (LD)l)
        {
  
            maxtime = midtime;
        }
        else
        {
           
            mintime = midtime;
        }
    }
    W(maxtime);
}
signed main()
{
    sync;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    for (int testcase = 1; testcase <= t; testcase++)
    {
        solve();
    }
    return 0;
}
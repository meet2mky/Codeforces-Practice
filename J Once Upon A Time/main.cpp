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
#define int long long
int gcd(int a, int b, int &x, int &y)
{
    // ax + by = gcd(a,b)
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    int x0, y0, gc = gcd(b % a, a, x0, y0);
    // (b - [b / a] * a) *x0 + a *y0 = gcd(a, b);
    // bx0 - [b/a]ax0 + ay0 = gcd(a,b);
    // a{ y0 - [b/a]x0 } + b{x0} = gcd(a,b);
    // a{ x            } + b{y } = gcd(a,b);
    y = x0;
    x = y0 - (b / a) * x0;
    return gc;
}
pair<bool, PII> find_any_solution(int a, int b, int c)
{
    int x, y;
    //  cerr << a << "x  + " << b << "y"
    //      << " == " << c << endl;
    int gc = gcd(abs(a), abs(b), x, y);
    //  cerr << "gcd: " << gc << endl;
    if (c % gc)
    {
        return {0, {-1, -1}};
    }

    x *= c / gc;
    y *= c / gc;
    if (a < 0)
        x = -x;
    if (b < 0)
        y = -y;
    return {1, {x, y}}; // any solution
    // we need a solution of type x >= 0 && y >= 0
}
void gentest()
{
    int t = 1000;
    srand(time(NULL));
    auto f = []() {
        return rand() % 10;
    };
    while (t--)
    {
        W(f(), f(), f(), f());
    }
    W(0, 0, 0, 0);
}
void solve()
{
    while (1)
    {
        int n, m, a, k;
        R(n, m, a, k);
        //   cerr << "Solving: ";
        //   cerr << n << ' ' << m << ' ' << a << ' ' << k << endl;
        if (n == 0 && m == 0 && a == 0 && k == 0)
        {
            exit(0);
        }
        if (n == m + k)
        {
            W(n);
        }
        else if (a == 0 && m != 0)
        {
            if (k - n >= m && (k - m) % m == 0)
            {
                W(k);
            }
            else
            {
                W("Impossible");
            }
        }
        else if (m == 0 && a != 0)
        {
            if (n - k >= a && (n - k) % a == 0)
            {
                W(n);
            }
            else
            {
                W("Impossible");
            }
        }
        else if (a == 0 && m == 0)
        {
            if (n == k)
            {
                W(n);
            }
            else
            {
                W("Impossible");
            }
        }
        else
        {
            // mx - ay = k + a - n
            //   cerr << "finding solution\n";
            auto any = find_any_solution(m, -a, k + a - n);
            if (any.first)
            {
                //  cerr << "got one\n";
                // W("have a solution: ", any.second);
                //  W(m, " * ", any.second.first, " ", -a, " * ", any.second.second, " === ", k + a - n);
            }
            else
            {
                // cerr << "no luck\n";
                W("Impossible");
                continue;
            }
            int x0 = any.second.first;
            int y0 = any.second.second;
            int upp = x0 / a;
            int low = (-y0 + m - 1) / m;
            if (upp >= low)
            {
                int t1 = n + m * (x0 - a * low);
                int t2 = n + m * (x0 - a * upp);
                if (t1 >= 1)
                {
                    int xx = (1 - t2 + m * a - 1) / (m * a);
                    W(t2 + xx * m * a);
                }
                else
                {
                    W("Impossible");
                }
            }
            else
            {
                //  W("HAVE A solution still no luck: ", n, m, a, k);
                W("Impossible");
            }
        }
    }
}
signed main()
{
    //  freopen("input.txt", "w", stdout);
    //  gentest();
    //  return 0;
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
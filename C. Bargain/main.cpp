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
template <typename T>
T gcd(T a, T b)
{
    return a == 0 ? b : gcd(b % a, a);
}
template <typename T>
T mulmod(T a, T b, T m)
{
    //assumed a and b in [0...(m-1)];
    return (a * b) % m;
}
template <typename T>
T addmod(T a, T b, T m)
{
    //assumed a and b in [0...(m-1)];
    return a + b >= m ? a + b - m : a + b;
}
template <typename T>
T submod(T a, T b, T m)
{
    //assumed a and b in [0...(m-1)];
    return a - b < 0 ? a - b + m : a - b;
}
template <typename T>
T powmod(T a, T e, T m)
{
    a %= m;
    if (e == 0)
        return 1;
    T ans = a;
    --e;
    while (e)
    {
        if (e & 1)
            ans = mulmod(a, ans, m);
        a = mulmod(a, a, m);
        e >>= 1;
    }
    return ans;
}
template <typename T>
T invmod(T a, T m)
{
    // assuming m is prime and greater than 2
    return powmod(a, m - 2, m);
}

template <typename T>
vector<T> facarray(T N, T m)
{
    vector<T> f_(N + 1, 1);
    for (T i = 2; i <= N; i++)
        f_[i] = mulmod(i, f_[i - 1], m);
    return f_;
}
template <typename T>
vector<T> invarray(T N, T m)
{
    vector<T> inv_(N + 1, 1);
    for (T i = 2; i <= N; i++)
    {
        inv_[i] = mulmod(m - m / i, inv_[m % i], m);
    }
    return inv_;
}
template <typename T>
vector<T> invfacarray(T N, T m)
{
    // assuming m is prime, using fermat's little theorem
    vector<T> f_ = facarray(N, m);
    vector<T> invf_(N + 1);
    invf_[N] = invmod(f_[N], m);
    for (T i = N - 1; i >= 0; i--)
    {
        invf_[i] = mulmod(i + 1, invf_[i + 1], m);
    }
    return invf_;
}
vector<bool> sieve_(int N)
{
    vector<bool> p(N + 1, true);
    p[0] = p[1] = false;
    for (int i = 2; i * i <= N; i++)
    {
        if (p[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                p[j] = false;
            }
        }
    }
    return p;
}
vector<int> spf_(int N)
{
    vector<int> spf(N + 1, 1);
    for (int i = 1; i <= N; i++)
        spf[i] = i;
    for (int i = 2; i * i <= N; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j <= N; j += i)
            {
                spf[j] = i;
            }
        }
    }
    return spf;
}
vector<int> primelist_(int N)
{
    vector<bool> p_ = sieve_(N);
    vector<int> p;
    for (int i = 2; i <= N; i++)
    {
        if (p_[i])
        {
            p.push_back(i);
        }
    }
    return p;
}
vector<pair<int, int>> prime_factorization_(int NUM, const vector<int> &spf_)
{
    vector<pair<int, int>> res;
    if (NUM == 1)
    {
        return res; // no primes
    }
    while (NUM > 1)
    {
        int P_here = spf_[NUM];
        int cnt = 0;
        while (spf_[NUM] == P_here)
        {
            NUM /= P_here;
            cnt++;
        }
        res.push_back({P_here, cnt});
    }
    return res;
}
const int N = 100006;
int pw[N];
int mod = 1e9 + 7;
void solve()
{
    pw[0] = 1;
    REP(i, 1, N)
    {
        pw[i] = mulmod(pw[i - 1], 10ll, mod);
    }
    int modi = invmod(81LL, mod);
    string str;
    cin >> str;
    int n = SZ(str);
    int y = 0;
    int x = n - 1;
    int res = 0;
    for (auto ch : str)
    {
       // W("dig = ", ch);
        int dig = ch - '0';
        int here = mulmod(9LL, x, mod);
        here = submod(here, 1LL, mod);
        here = mulmod(here, pw[x], mod);
        here = addmod(here, 1LL, mod);
        here = mulmod(here, modi, mod);
        here = mulmod(dig, here, mod);
      //  W("back = ", here);
        res = addmod(res, here, mod);
        here = (y * (y + 1)) / 2LL;
        here %= mod;
        here = mulmod(here, pw[x], mod);
        here = mulmod(here, dig, mod);
     //   W("front= ", here);
        res = addmod(res, here, mod);
        y++;
        x--;
    }
    W(res);
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
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
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define repinv(i, a, b) for (int i = (a); i > (b); i--)
#define all(x) (x).begin(), (x).end()
#define setall(x, val) fill(all(x), val)
#define odd(x) (x & 1)
#define even(x) (!(x & 1))
#define pb push_back
#define vb vector<bool>
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define sp(x) setprecision(x)
#define endl '\n'
#define ll long long
#define ld long double
#define SZ(z) (int)(z).size()
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define eps 0.0000001 // eps = 1e-7
#define PI 3.141592653589793238

#define int long long
const int MOD = 1000000007;
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
//variadic functions
template <typename T>
T sum() { return 0; }
template <typename T, typename... Args>
T sum(T a, Args... args) { return a + sum(args...); }

//Debugger  -------------------------------------------->
#define error(args...)                           \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }

void err(istream_iterator<string> it)
{
}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
//Debugger  <--------------------------------------------
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

void solve()
{
    int n;
    cin >> n;
    vi a(n);
    vi b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    map<pii, int> mp;
    int ansmaybe = 0;
    rep(i, 0, n)
    {
        if (b[i] == 0)
            ansmaybe++;
    }
    // d !=0;
    int ansposs = 0;
    rep(i, 0, n)
    {
        int aa = a[i];
        int bb = b[i];
        int sign = 1;
        if (aa < 0)
        {
            sign *= -1;
            aa = -aa;
        }
        if (bb < 0)
        {
            sign *= -1;
            bb = -bb;
        }
        if (aa == 0 || bb == 0)
        {
            if (aa == 0 && bb == 0)
                ansposs++;
        }
        else
        {
            int gc = gcd(aa, bb);
            aa /= gc;
            bb /= gc;
            mp[{sign * bb, aa}]++;
        }
    }
    int mx = 0;
    for (auto now : mp)
    {
        mx = max(mx, now.second);
    }
    cout << max(ansmaybe, ansposs + mx);
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
#ifndef ONLINE_JUDGE
        error(testcase);
#endif
        solve();
    }
    return 0;
}
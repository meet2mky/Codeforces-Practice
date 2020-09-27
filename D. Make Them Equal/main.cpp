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

//#define int long long
const int MOD = 1000000007;

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

void print(vi a)
{
    for (int i = 1; i < SZ(a); i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
}
void solve()
{
    int n;
    cin >> n;
    vi a(n + 1);
    int sum = 0;
    rep(i, 1, n + 1)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % n != 0)
    {
        cout << "-1" << endl;
        return;
    }
    int T = sum / n;
    vi ops;
    rep(i, 2, n + 1)
    {
        if (a[i] % i != 0)
        {
            int need = i - a[i] % i;

            ops.push_back(1);
            ops.push_back(i);
            ops.push_back(need);
            a[1] -= need;
            a[i] += need;
        }

        ops.push_back(i);
        ops.push_back(1);
        ops.push_back(a[i] / i);
        a[1] += a[i];
        a[i] = 0;
    }
    rep(i, 2, n + 1)
    {

        ops.push_back(1);
        ops.push_back(i);
        ops.push_back(T);
        a[1] -= T;
        a[i] += T;
    }
    cout << SZ(ops) / 3 << endl;
    for (int i = 0; i < SZ(ops); i += 3)
    {
        cout << ops[i] << " " << ops[i + 1] << " " << ops[i + 2] << endl;
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
    cin >> t;
    for (int testcase = 1; testcase <= t; testcase++)
    {
#ifndef ONLINE_JUDGE
        error(testcase);
#endif
        solve();
    }
    return 0;
}
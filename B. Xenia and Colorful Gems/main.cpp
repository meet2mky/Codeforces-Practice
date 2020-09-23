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
#define SQ(z) ((z) * (z))
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define eps 0.0000001 // eps = 1e-7
#define PI 3.141592653589793238

#define int long long
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

void solve()
{
    int r, g, b, pos;
    cin >> r >> g >> b;
    vector<pair<int, char>> vec(r + g + b);
    rep(i, 0, r)
    {
        cin >> pos;
        vec[i] = {pos, 'r'};
    }
    rep(i, 0, g)
    {
        cin >> pos;
        vec[i + r] = {pos, 'g'};
    }
    rep(i, 0, b)
    {
        cin >> pos;
        vec[i + r + g] = {pos, 'b'};
    }
    sort(all(vec));
    int pr = 0;
    int pg = 0;
    int pb = 0;
    int dpleft[3][r + g + b];
    int dpright[3][r + g + b];
    memset(dpleft, 0, sizeof dpleft);
    memset(dpright, 0, sizeof dpright);
    map<char, int> mp;
    mp['r'] = 0;
    mp['g'] = 1;
    mp['b'] = 2;
    dpleft[mp[vec[0].second]][0] = vec[0].first;
    rep(i, 1, r + g + b)
    {
        dpleft[mp[vec[i].second]][i] = vec[i].first;
        rep(j, 0, 3)
        {
            if (j == mp[vec[i].second])
                continue;
            dpleft[j][i] = dpleft[j][i - 1];
        }
    }
    dpright[mp[vec[r + g + b - 1].second]][r + g + b - 1] = vec[r + g + b - 1].first;
    repinv(i, r + g + b - 2, -1)
    {
        dpright[mp[vec[i].second]][i] = vec[i].first;
        rep(j, 0, 3)
        {
            if (j == mp[vec[i].second])
                continue;
            dpright[j][i] = dpright[j][i + 1];
        }
    }
    int minans = linf;

    rep(i, 1, r + g + b - 1)
    {
        int a, b;
        if (vec[i].second == 'r')
        {
            a = 1, b = 2;
        }
        if (vec[i].second == 'g')
        {
            a = 0, b = 2;
        }
        if (vec[i].second == 'b')
        {
            a = 0, b = 1;
        }
        int mid = vec[i].first;
        int left = dpleft[a][i - 1];
        int right = dpright[b][i + 1];
        if (left != 0 && right != 0)
        {
            minans = min(minans, SQ(mid - left) + SQ(right - mid) + SQ(right - left));
        }
        swap(a, b);
        mid = vec[i].first;
        left = dpleft[a][i - 1];
        right = dpright[b][i + 1];
        if (left != 0 && right != 0)
        {
            minans = min(minans, SQ(mid - left) + SQ(right - mid) + SQ(right - left));
        }
    }
    cout << minans << endl;
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
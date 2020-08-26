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
#include <cassert>
#include <cctype>
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
#define repi(i, a, b) for (int i = (a); i > (b); i--)
#define all(x) (x).begin(), (x).end()
#define setall(x, val) fill(all(x), val)
#define pb push_back
#define mp make_pair
#define vb vector<bool>
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define endl '\n'
#define MOD 1000000007
#define ll long long
#define ld long double
#define SZ(z) (int)(z).size()
#define test(t) \
    int t;      \
    cin >> t;   \
    while (t--)

//#define int long long
#define inf 0x3f3f3f3f

//variadic functions
template <typename T>
T sum() { return 0; }
template <typename T, typename... Args>
T sum(T a, Args... args) { return a + sum(args...); }

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

void solve()
{
    test(zzz)
    {
        /*int p, f, cnts, cntw, s, w;
        cin >> p >> f >> cnts >> cntw >> s >> w;
        int res = 0;
        if (s > w)
        {
            swap(s, w);
            swap(cnts, cntw);
        }
        int mn = min(p / s, cnts);
        res += mn;
        cnts -= mn;
        p -= s * mn;
 
        mn = min(f / s, cnts);
        res += mn;
        cnts -= mn;
        f -= s * mn;
 
        mn = min(f / w, cntw);
        res += mn;
        cntw -= mn;
        f -= w * mn;
 
        mn = min(p / w, cntw);
        res += mn;
        cntw -= mn;
        p -= w * mn;
 
        cout << res << '\n';
        */
        string s;
        cin >> s;
        int x;
        cin >> x;
        int n = SZ(s);
        string w(n, '1');
        rep(i, 0, n)
        {
            if (s[i] == '0')
            {
                int lx = i - x;
                int rx = i + x;
                if (lx >= 0)
                {
                    w[lx] = '0';
                }
                if (rx < n)
                {
                    w[rx] = '0';
                }
            }
        }
        bool ok = true;
        rep(i, 0, n)
        {
            if (s[i] == '1')
            {
                bool here = false;
                int lx = i - x;
                int rx = i + x;
                if (lx >= 0)
                {
                    if (w[lx] == '1')
                        here = true;
                }
                if (rx < n)
                {
                    if (w[rx] == '1')
                    {
                        here = true;
                    }
                }
                ok &= here;
            }
        }
        if (ok)
        {
            cout << w << '\n';
        }
        else
        {
            cout << "-1\n";
        }
    }
}

signed main()
{
    sync;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
    return 0;
}
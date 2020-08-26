#define dbg(x) cout << #x << " is: " << x << endl
#include <bits/stdc++.h>
using namespace std;
struct VAR
{
    int seqLen;
    int open;
    int close;
};
void ini(VAR &t, char x)
{
    if (x == '(')
    {
        t.open = 1;
    }
    else
    {
        t.close = 1;
    }
}
VAR combine(VAR &a, VAR &b)
{
    VAR tmp;
    tmp.seqLen = a.seqLen + b.seqLen + min(a.open, b.close);
    tmp.close = a.close + b.close - min(a.open, b.close);
    tmp.open = a.open + b.open - min(a.open, b.close);
    return tmp;
}
const int N = 1e6 + 10;
int n;
VAR t[2 * N];
void build()
{
    for (int i = n - 1; i > 0; i--)
    {
        t[i] = combine(t[i << 1], t[i << 1 | 1]);
    }
}
VAR query(int l, int r)
{
    VAR resr, resl;
    resr.seqLen = resl.seqLen = resr.open = resr.close = resl.open = resl.close = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            resl = combine(resl, t[l++]);
        if (r & 1)
            resr = combine(t[--r], resr);
    }
    return combine(resl, resr);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    n = (int)s.size();
    for (int i = 0; i < n; i++)
    {
        ini(t[i + n], s[i]);
    }
    build();
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        VAR x = query(l - 1, r);
        cout << x.seqLen + x.seqLen << endl;
    }
    return 0;
}
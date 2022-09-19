#include <iostram>
#include <bits/stdc++.h>
using namespace std;
#def long long ll
void solve(int ts)
{

    ll n, q;
    cin >> n;
    vector<ll> x1(n), y1(n);
    for (ll i = 0; i < n; i++)
        cin >> x1[i] >> y1[i];

    cin >> q;
    vector<ll> x2(q), y2(q);
    for (ll i = 0; i < q; i++)
        cin >> x2[i] >> y2[i];

    ll ans = 0, p1 = 0, p2 = 0;
    for (ll j = 0; j < n; j++)
        ans = (ans + q * (x1[j] * x1[j] + y1[j] * y1[j]));

    for (ll i = 0; i < q; i++)
        ans = (ans + n * (x2[i] * x2[i] + y2[i] * y2[i]));

    for (ll i = 0; i < n; i++)
    {
        p1 += x1[i];
        p2 += y1[i];
    }
    for (ll j = 0; j < q; j++)
    {
        ans -= 2 * (p1 * x2[j] + p2 * y2[j]);
    }

    cout << "Case #" << ts << ": " << ans % mod << endl;
}
int main()
{
    solve();
    return 0;
}
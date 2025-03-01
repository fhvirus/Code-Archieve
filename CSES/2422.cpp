#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  ll n;
  cin >> n;

  ll ans = 0, target = n * n / 2 + 1;
  for (ll l = 1ll << 40; l > 0; l /= 2) {
    ll t = ans + l;
    ll cnt = 0;
    rep (i, 1, n + 1)
      cnt += min(n, t / i);
    if (cnt < target) ans = t;
  }

  cout << ans + 1 << '\n';

  return 0;
}


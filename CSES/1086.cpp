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

  ll ans = 0;
  for (ll l = (1ll << 58); l > 0; l >>= 1) {
    ll t = ans + l;
    // digit one or zero appears the most, so just count them
    ll cnt0 = 0, cnt1 = 0;
    for (ll base = 1; base <= t; base *= 10) {
      ll a = t / (base * 10), b = t - a * base * 10;
      cnt0 += (a - 1) * base; // full loop
      cnt1 += a * base;
      cnt0 += min(b + 1, base);
      cnt1 += max(0ll, min(b - base + 1, base));
    }
    if (max(cnt0, cnt1) <= n)
      ans = t;
  }
  cout << ans << '\n';

  return 0;
}

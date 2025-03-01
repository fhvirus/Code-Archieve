#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct BIT {
  vi val;
  BIT (int n) : val(n) {}
  void modify(int p, int v) {
    for (; p < sz(val); p += p & -p)
      val[p] += v;
  }
  int query(int p) {
    int res = 0;
    for (; p > 0; p -= p & -p)
      res += val[p];
    return res;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n;
  cin >> n;

  vi x(n);
  for (int &i : x) cin >> i;

  vi ord(n); iota(all(ord), 0);
  sort(all(ord), [&](int u, int v) { return x[u] < x[v]; });

  BIT bit(n + 1);
  rep (i, 0, n) bit.modify(i + 1, 1);

  ll ans = 0;
  rep (i, 0, n) {
    bit.modify(ord[i] + 1, -1);
    int cnt = bit.query(ord[i] + 1);
    ans += min(cnt, n - i - 1 - cnt);
  }
  cout << ans << '\n';

  return 0;
}

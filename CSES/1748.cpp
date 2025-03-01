#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MOD = 1e9 + 7;
int mad(int u, int v) {
  u += v - MOD;
  return u + (u >> 31 & MOD);
}

struct BIT {
  vi val;
  BIT (int n) : val(n) {}
  void modify(int p, int v) {
    for (; p < sz(val); p += p & -p)
      val[p] = mad(val[p], v);
  }
  int query(int p) {
    int res = 0;
    for (; p > 0; p -= p & -p)
      res = mad(res, val[p]);
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

  vi a = x; a.push_back(0); sort(all(a)); a.erase(unique(all(a)), end(a));
  for (int &i : x) i = (int) (lower_bound(all(a), i) - begin(a)) + 1;

  BIT bit(sz(a) + 1);
  bit.modify(1, 1);

  for (int i : x) {
    int val = bit.query(i - 1);
    bit.modify(i, val);
  }

  cout << mad(bit.query(sz(a)), MOD - 1) << '\n';

  return 0;
}

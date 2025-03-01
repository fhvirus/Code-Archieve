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

  ll n, k;
  cin >> n >> k;

  ll t = n;
  while (t > 0 and k >= t - 1) {
    cout << t-- << ' ';
    k -= t;
  }
  if (t > 0) {
    rep (i, 0, k) cout << i + 2 << ' ';
    cout << 1 << ' ';
    rep (i, k + 2, t + 1) cout << i << ' ';
  }
  cout << '\n';

  return 0;
}

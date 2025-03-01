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

  int n;
  cin >> n;

  vi k(n + 2);
  rep (i, 1, n + 1)
    cin >> k[i];

  vi stk(1, 0);
  ll ans = 0;
  rep (i, 1, n + 2) {
    while (k[i] <= k[stk.back()]) {
      ll h = k[stk.back()];
      stk.pop_back();
      if (stk.empty()) break;
      ans = max(ans, h * (i - stk.back() - 1));
    }
    stk.push_back(i);
  }

  cout << ans << '\n';

  return 0;
}

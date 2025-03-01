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

  const int mod = 1e9 + 7;
  const auto mad = [mod](int u, int v) {
    u += v;
    return u - (u >= mod ? mod : 0);
  };

  int n, k;
  cin >> n >> k;

  vi dp(k + 1), sc(k + 1, 1);
  rep (i, 2, n + 1) {
    rep (j, 0, k + 1) {
      int lb = max(j - (i - 1), 0);
      dp[j] = mad(sc[j], lb > 0 ? mod - sc[lb - 1] : 0);
      if (j > 0) dp[j] = mad(dp[j], dp[j - 1]);
    }
    swap(dp, sc);
  }

  cout << mad(sc[k], k > 0 ? mod - sc[k - 1] : 0) << '\n';

  return 0;
}

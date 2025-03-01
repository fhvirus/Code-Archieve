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

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  string s;
  cin >> s;
  s = ' ' + s;
  int n = sz(s);

  vi dp(n, 0), prv(26, 0);
  dp[0] = 1;

  rep (i, 1, n) {
    int c = s[i] - 'a';
    dp[i] = mad(dp[i - 1], dp[i - 1]);
    if (prv[c] > 0)
      dp[i] = mad(dp[i], MOD - dp[prv[c] - 1]);
    prv[c] = i;
  }

  cout << mad(dp.back(), MOD - 1) << '\n';

  return 0;
}

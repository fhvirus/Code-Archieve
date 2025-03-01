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

  vi x(n + 1);
  rep (i, 1, n + 1) {
    cin >> x[i];
    x[i] ^= x[i - 1];
  }

  vector<array<int, 2>> trie(1, {0, 0});
  int ans = 0;
  for (int i : x) {
    int u = 0, cur = 0;
    for (int l = 30; l >= 0; --l) {
      cur <<= 1;
      int t = ((i >> l) & 1);
      if (trie[u][t ^ 1] == 0) u = trie[u][t];
      else {
        u = trie[u][t ^ 1];
        cur |= 1;
      }
    }
    ans = max(ans, cur);
    u = 0;
    for (int l = 30; l >= 0; --l) {
      int t = ((i >> l) & 1);
      if (trie[u][t] == 0) {
        trie[u][t] = sz(trie);
        trie.push_back({0, 0});
      }
      u = trie[u][t];
    }
  }

  cout << ans << '\n';

  return 0;
}

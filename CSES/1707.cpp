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

  int n, m;
  cin >> n >> m;

  vector<vi> adj(n + 1);
  for (int u, v, i = 0; i < m; ++i) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int ans = INT_MAX;

  for (int s = 1; s <= n; ++s) {
    vi dis(n + 1, -1), par(n + 1, -1), ord;
    for (int v : adj[s])
      dis[v] = 1, par[v] = v, ord.push_back(v);
    rep (i, 0, sz(ord)) {
      int u = ord[i];
      for (int v : adj[u]) if (v != s and par[v] != par[u]) {
        if (par[v] == -1) {
          dis[v] = dis[u] + 1;
          par[v] = par[u];
          ord.push_back(v);
        } else ans = min(ans, dis[u] + dis[v] + 1);
      }
    }
  }

  cout << (ans == INT_MAX ? -1 : ans) << '\n';

  return 0;
}

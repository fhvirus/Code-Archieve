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
  for (int a, b, i = 0; i < m; ++i) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<pii> ans;
  vi num(n + 1);
  int tot = 0;
  const auto dfs = [&](const auto& self, int u, int p) -> int {
    num[u] = ++tot;
    int out_deg = 0;
    for (int v : adj[u]) if (v != p) {
      if (num[v] == 0) {
        int need = self(self, v, u);
        if (need) ans.emplace_back(v, u);
        else ans.emplace_back(u, v), out_deg += 1;
      } else if (num[v] < num[u]) {
        ans.emplace_back(u, v);
        out_deg += 1;
      }
    }
    return out_deg % 2;
  };

  rep (i, 1, n + 1) if (num[i] == 0) {
    if (dfs(dfs, i, 0)) {
      cout << "IMPOSSIBLE\n";
      return 0;
    }
  }

  for (auto [u, v] : ans) cout << u << ' ' << v << '\n';

  return 0;
}


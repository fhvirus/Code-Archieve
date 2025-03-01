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

  vi num(n + 1);
  int tot = 0;
  vector<pii> ans;
  bool can = true;
  const auto dfs = [&](const auto& self, int u, int p) -> int {
    int low = num[u] = ++tot;
    for (int v : adj[u]) if (v != p) {
      if (num[v]) {
        low = min(low, num[v]);
        if (num[v] < num[u])
          ans.emplace_back(u, v);
      } else {
        ans.emplace_back(u, v);
        int vlow = self(self, v, u);
        low = min(low, vlow);
        if (vlow > num[u]) can = false;
      }
    }
    return low;
  };
  dfs(dfs, 1, 0);

  rep (i, 1, n + 1) if (num[i] == 0) can = false;

  if (not can) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }

  for (auto [u, v] : ans)
    cout << u << ' ' << v << '\n';

  return 0;
}


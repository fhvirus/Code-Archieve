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

  vector<vi> adj(n + 1);
  for (int u, v, i = 1; i < n; ++i) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vi leaves;
  const auto dfs = [&](const auto& self, int u, int p) -> void {
    if (sz(adj[u]) == 1) leaves.push_back(u);
    for (int v : adj[u]) if (v != p)
      self(self, v, u);
  };
  dfs(dfs, 1, 0);

  if (sz(leaves) % 2 == 1) leaves.push_back(leaves[0]);
  int k = sz(leaves) / 2;
  cout << k << '\n';
  rep (i, 0, k)
    cout << leaves[i] << ' ' << leaves[i + k] << '\n';

  return 0;
}

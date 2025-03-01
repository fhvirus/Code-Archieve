#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int permToInt(vi& v) {
  int use = 0, i = 0, r = 0;
  for(int x:v) r = r * ++i + __builtin_popcount(use & -(1<<x)),
    use |= 1 << x;
  return r;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  const vector<pii> adj = {
    {0, 1}, {1, 2},
    {3, 4}, {4, 5},
    {6, 7}, {7, 8},
    {0, 3}, {3, 6},
    {1, 4}, {4, 7},
    {2, 5}, {5, 8}
  };

  vector<vi> itop(362880);
  {
    vi a(9); iota(all(a), 1);
    do { itop[permToInt(a)] = a; }
    while (next_permutation(all(a)));
  }

  vi a(9);
  for (int &i : a) cin >> i;
  int va = permToInt(a);
  if (va == 0) {
    cout << 0 << '\n';
    return 0;
  }

  queue<int> q;
  vi dis(sz(itop), -1);
  dis[va] = 0;
  q.push(va);

  while (!q.empty()) {
    int u = q.front(); q.pop();
    int d = dis[u];
    auto au = itop[u];
    for (auto [i, j] : adj) {
      swap(au[i], au[j]);
      int v = permToInt(au);
      if (v == 0) {
        cout << d + 1 << '\n';
        return 0;
      }
      if (dis[v] == -1) {
        dis[v] = d + 1;
        q.push(v);
      }
      swap(au[j], au[i]);
    }
  }

  assert(0);

  return 0;
}

#include <bits/stdc++.h>
using namespace std;

struct DSU {
  vector<int> f;
  DSU (int n) : f(n, -1) {}
  int find(int u) { return f[u] < 0 ? u : f[u] = find(f[u]); }
  void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return;
    if (f[u] > f[v]) swap(u, v);
    f[u] += exchange(f[v], u);
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int A, B, C;
  while (cin >> A >> B >> C) {
    vector<int> x(B + 1), y(B + 1);
    x[0] = y[0] = A;
    for (int i = 1; i <= B; ++i) {
      x[i] = (269 * x[i - 1] + 11) % 103;
      y[i] = (271 * y[i - 1] + 13) % 97;
    }

    DSU dsu(B + 1);
    for (int i = 1; i <= B; ++i) {
      for (int j = i + 1; j <= B; ++j)
        if ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) <= C * C)
          dsu.merge(i, j);
    }

    vector<int> cnt(B + 1);
    for (int i = 1; i <= B; ++i) cnt[dsu.find(i)] += 1;
    sort(begin(cnt), end(cnt), greater());
    while (cnt.back() == 0) cnt.pop_back();

    cout << cnt.size() << '\n';
    reverse(begin(cnt), end(cnt));
    for (int i : cnt) cout << i << ' ';
    cout << '\n';
  }

  return 0;
}

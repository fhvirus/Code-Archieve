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

  int n, q;
  cin >> n >> q;

  vector<pii> movies(n);
  for (auto &[a, b] : movies)
    cin >> a >> b;

  int C = 0;
  for (const auto &[a, b] : movies) C = max(C, b);
  const int L = __lg(n) + 1, INF = C + 1;

  vector<vi> next_end(L, vi(C + 1, INF));
  for (const auto &[a, b] : movies)
    next_end[0][a] = min(next_end[0][a], b);
  for (int i = C - 1; i >= 0; --i)
    next_end[0][i] = min(next_end[0][i], next_end[0][i + 1]);
  rep (l, 1, L) rep (i, 0, C)
    next_end[l][i] = 
      (next_end[l - 1][i] == INF ? INF :
       next_end[l - 1][next_end[l - 1][i]]);

  for (int a, b, i = 0; i < q; ++i) {
    cin >> a >> b;
    int ans = 0;
    for (int l = L - 1; l >= 0; --l)
      if (next_end[l][a] <= b) {
        a = next_end[l][a];
        ans += (1 << l);
      }
    cout << ans << '\n';
  }

  return 0;
}


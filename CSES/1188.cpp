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

  string b;
  cin >> b;
  int n = sz(b);

  set<int> s;
  s.insert(0);
  s.insert(n);

  rep (i, 0, n)
    if (b[i] != b[i + 1])
      s.insert(i + 1);

  multiset<int> lens;
  for (auto it = begin(s); next(it) != end(s); it = next(it))
    lens.insert(*next(it) - *it);

  int m;
  cin >> m;

  debug(b, s, lens);

  for (int x, i = 0; i < m; ++i) {
    cin >> x; x -= 1;
    for (int p : {x, x + 1}) if (p > 0 and p < n and b[p - 1] != b[p]) {
      auto it = s.find(p);
      it = s.erase(it);
      lens.erase(lens.find(*it - p));
      lens.erase(lens.find(p - *prev(it)));
      lens.insert(*it - *prev(it));
    }
    b[x] = "01"[b[x] == '0'];
    for (int p : {x, x + 1}) if (p > 0 and p < n and b[p - 1] != b[p]) {
      auto it = s.insert(p).first;
      lens.erase(lens.find(*next(it) - *prev(it)));
      lens.insert(*next(it) - p);
      lens.insert(p - *prev(it));
    }
    cout << *prev(end(lens)) << " \n"[i == m - 1];
  }
  

  return 0;
}

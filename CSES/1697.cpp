#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void fail() { 
  cout << "IMPOSSIBLE\n";
  exit(0);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n;
  cin >> n;

  int sum = 0;
  set<pii> s;
  for (int x, i = 1; i <= n; ++i) {
    cin >> x;
    sum += x;
    s.emplace(x, i);
  }

  if (sum % 2 != 0 or prev(end(s))->first * 2 > sum) fail();

  vector<pii> ans;
  while (not s.empty()) {
    auto [mnx, mni] = *begin(s);
    s.erase(begin(s));
    vector<pii> matches;
    rep (_, 0, mnx) {
      if (s.empty()) fail();
      auto [mxx, mxi] = *prev(end(s));
      s.erase(prev(end(s)));
      ans.emplace_back(mni, mxi);
      if (mxx > 1) matches.emplace_back(mxx - 1, mxi);
    }
    for (auto [x, i] : matches)
      s.emplace(x, i);
  }

  cout << sum / 2 << '\n';
  for (auto [a, b] : ans)
    cout << a << ' ' << b << '\n';

  return 0;
}

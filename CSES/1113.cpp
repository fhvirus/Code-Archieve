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
  
  string s;
  cin >> s;

  vector<vi> bkt(128);
  rep (i, 0, sz(s))
    bkt[s[i]].push_back(i);

  vi ord;
  for (int i = 0, p = 0; i < 128; ++i)
    for (int j : bkt[i])
      ord.push_back(j), s[p++] = char(i);

  string res(sz(s), ' ');
  for (int i = 0, p = 0; i < sz(s); ++i) {
    res[i] = s[ord[p]];
    p = ord[p];
  }
  rotate(begin(res), find(all(res), '#') + 1, end(res));
  res.pop_back();

  cout << res << '\n';

  return 0;
}

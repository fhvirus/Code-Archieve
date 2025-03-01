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

  vector<bool> has(26);
  for (char c : s)
    has[c - 'a'] = true;

  ll ans = 0;
  map<vi, int> mp;
  vi cnt(26, 0);
  mp[cnt] = 1;
  for (char c : s) {
    cnt[c - 'a'] += 1;
    int min_val = INT_MAX;
    rep (j, 0, 26) if (has[j]) min_val = min(min_val, cnt[j]);
    rep (j, 0, 26) if (has[j]) cnt[j] -= min_val;
    ans += mp[cnt];
    mp[cnt] += 1;
  }

  cout << ans << '\n';

  return 0;
}
